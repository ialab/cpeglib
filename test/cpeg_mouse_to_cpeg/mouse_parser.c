#include "mouse_parser.h"
#include "string.h"

/*
  START <- Definition*
  Definition <- Name '=' Choice ';'
  Name <- Letter LetterOrDigit*
  Letter <- [A-Z] / [a-z]
  LetterOrDigit <- Letter / [0-9]
  Choice <- Term+ ('/' Choice)*
  Term <- Unary (("*+" / "++") Unary / ('*' / '+' / '?'))*
  Unary <- ('!' / '&')* Primary
  Primary <- CharClass / String / Char / '(' Choice ')' / Any / Name
  CharClass <- Range / CharSet / NotCharSet
  Range <- '[' CharSetChar '-' CharSetChar  ']'
  CharSet <- '[' CharSetChar+ ']'
  NotCharSet <- "^[" CharSetChar+ ']'
  CharSetChar <- Escape
          
                 / !(']' / '-') _
  Escape <- '\\' ([rn\\t] / 
                 'u' HexDigit HexDigit HexDigit HexDigit /
                  _ )
  HexDigit <- [0-9] / [a-f] / [A-F]
  String <- '"' (!'"' (Escape / _))* '"'
  Char <- '\'' ! '\'' (Escape / _) '\''

  Space <- ([ \t\n\r\f] / "//" (!'\n' _)*)*
*/

DECLARE_RULES(Space, Definition, Name, 
	      Choice, Term, Unary, Primary,
	      Range, CharSet, NotCharSet, CharSetBody,
	      String, CharSetChar, Char, Escape)

cpeg_charset_t space_set, 	/* used in Space */
  letter_set, 			/* [a-zA-Z] */
  letter_or_digit_set,		/* [a-zA-Z0-9] */
  hex_digit_set,		/* [0-9a-fA-F] */
  charset_set,			/* any char that can appear in [..] */
  string_set,			/* any char that can appear in ".." */
  char_set;			/* any char that can appear in '..' */

mouse_ast_t mouse_any;		/* AST for _ */

static mouse_ast_t binary(M_TYPE type, mouse_ast_t left, mouse_ast_t right) {
  return mouse_ast_new_binary(type, left, right);
}

static mouse_ast_t unary(M_TYPE type, mouse_ast_t arg) {
  return mouse_ast_new_unary(type, arg);
}

BEGIN_RULE(Space) {
  REPEAT0(ALT(CHARSET(space_set),
	      SEQ(CHAR('/'), CHAR('/'), REPEAT0(SEQ(NOTPRE(CHAR('\n')), ANY())))));
}
END_RULE

#define TOKEN(e) SEQ(Space(), e)
#define T_CHAR(c) TOKEN(CHAR(c))

BEGIN_RULE(START) {
  cs_simple(space_set, ' ');
  cs_simple(space_set, '\t');
  cs_simple(space_set, '\n');
  cs_simple(space_set, '\r');
  cs_simple(space_set, '\f');
       
  cs_range(hex_digit_set, '0', '9');
  cs_range(hex_digit_set, 'a', 'f');
  cs_range(hex_digit_set, 'A', 'F');

  cs_range(letter_set, 'a', 'z');
  cs_range(letter_set, 'A', 'Z');

  cs_range(letter_or_digit_set, '0', '9');
  cs_union(letter_or_digit_set, letter_set);

  cs_simple(charset_set, ']');
  cs_simple(charset_set, '-');
  cs_simple(charset_set, '\\');
  cs_complement(charset_set);

  cs_simple(string_set, '"');
  cs_simple(string_set, '\\');
  cs_complement(string_set);

  cs_simple(char_set, '\'');
  cs_simple(char_set, '\\');
  cs_complement(char_set);

  string_t anystr = string_new();
  string_append(anystr, '_');
  mouse_any = mouse_ast_new_leaf(M_ANY, anystr);

  mouse_list_t children = mouse_list_new();
  REPEAT0(SEQ(Definition(),
	      children = mouse_list_append(children, val),
	      Space()));
  val = mouse_ast_new_interior_from_list(M_SEQ, children);
}
END_RULE

/* Expect result of START.  */
void print_mouse_ast(cpeg_value_t result, char *input, cpeg_pos_t pos, size_t size) {
  mouse_list_iterator_t iter = mouse_list_iterator(mouse_ast_children(result));
  while (mouse_list_iterator_has_next(iter)) {
    mouse_ast_print(mouse_list_iterator_next(iter), stdout);
    printf("\n");
  }
}

BEGIN_RULE(Definition) {
  mouse_ast_t name;
  mouse_ast_t body;
  SEQ(Name(), name = val,
      T_CHAR('='),
      Choice(), body = val,
      T_CHAR(';'));
  val = binary(M_DEF, name, body);
}
END_RULE

BEGIN_RULE(Name) {
  string_t str = string_new();
  TOKEN(SEQ(CHARSET(letter_set), string_append(str, AS_CHAR(val)),
	    REPEAT0(SEQ(CHARSET(letter_or_digit_set), 
			string_append(str, AS_CHAR(val))))));
  val = mouse_ast_new_leaf(M_NAME, str);
}
END_RULE

BEGIN_RULE(Choice) {
  mouse_list_t children = mouse_list_new();
  mouse_list_t seq = mouse_list_new();

  SEQ(REPEAT1(SEQ(Term(), mouse_list_append(seq, val))),
      children = mouse_list_append(children,
				   mouse_ast_new_interior_from_list(M_SEQ, seq)),
      REPEAT0(SEQ(T_CHAR('/'),
		  seq = mouse_list_new(),
		  REPEAT1(SEQ(Term(), mouse_list_append(seq, val))),
		  children = mouse_list_append(children,
					       mouse_ast_new_interior_from_list(M_SEQ, seq)))));
  val = mouse_ast_new_interior_from_list(M_CHOICE, children);
}
END_RULE

mouse_ast_t make_UNTIL(M_TYPE repeat0_or_1, mouse_ast_t left, mouse_ast_t right) {
  // SEQ(REPEAT[01](SEQ(NOTPRE(right), left)), right)
  return binary(M_SEQ,
		unary(repeat0_or_1,
		      binary(M_SEQ,
			     unary(M_NOT, right),
			     left)),
		right);
}

BEGIN_RULE(Term) {
  mouse_ast_t result;
  SEQ(Unary(), result = val, 
      REPEAT0(SEQ(Space(),
		  ALT(SEQ(STR("*+"), Unary(),
			  //result = binary(M_UNTIL0, result, val)),
			  result = make_UNTIL(M_REP0, result, val)),
		      SEQ(STR("*-"), Unary(),
			  // result = binary(M_UNTIL1, result, val)),
			  result = make_UNTIL(M_REP0, result, val)),
		      SEQ(CHAR('*'), result = unary(M_REP0, result)),
		      SEQ(CHAR('+'), result = unary(M_REP1, result)),
		      SEQ(CHAR('?'), result = unary(M_OPT, result))))));
  val = result;
}
END_RULE

BEGIN_RULE(Unary) {
  ALT(SEQ(TOKEN(CHAR('!')), Unary(), val = unary(M_NOT, val)),
      SEQ(TOKEN(CHAR('&')), Unary(), val = unary(M_AND, val)),
      Primary());
}
END_RULE

BEGIN_RULE(Primary)
{
  mouse_ast_t result;
  SEQ(Space(),
      ALT(Range(), CharSet(), NotCharSet(),
	  String(),
	  Char(),
	  SEQ(CHAR('('), Choice(), result = val, TOKEN(CHAR(')')), val = result),
	  SEQ(CHAR('_'), val = mouse_any),
	  Name()));
}
END_RULE

BEGIN_RULE(Range)
{
  char c1, c2;
  string_t str;
  SEQ(CHAR('['),
      CharSetChar(), c1 = AS_CHAR(val),
      CHAR('-'), 
      CharSetChar(), c2 = AS_CHAR(val),
      CHAR(']'),
      (str = string_new(),
       str = string_append(str, c1),
       str = string_append(str, c2),
       val = mouse_ast_new_leaf(M_RANGE, str)));
}
END_RULE

BEGIN_RULE(CharSet)
{
  string_t str;
  SEQ(CHAR('['),
      str = string_new(),
      REPEAT1(SEQ(CharSetChar(), str = string_append(str, AS_CHAR(val)))),
      CHAR(']'));
  val = mouse_ast_new_leaf(M_CHARSET, str);
}
END_RULE

BEGIN_RULE(NotCharSet)
{
  string_t str;
  SEQ(CHAR('^'), CHAR('['),
      str = string_new(),
      REPEAT1(SEQ(CharSetChar(), str = string_append(str, AS_CHAR(val)))),
      CHAR(']'));
  val = mouse_ast_new_leaf(M_NOTCHARSET, str);
}
END_RULE

BEGIN_RULE(CharSetChar)
{
       ALT(CHARSET(charset_set), Escape());
}
END_RULE

int h2i(char ch) {
  if (ch <= '9') {
    return ch - '0';
  } else if (ch <= 'F') {
    return ch - 'A' + 10;
  } else {
    return ch - 'a' + 10;
  }
}

BEGIN_RULE(Escape)
{
  int ch1, ch2, ch3, ch4;
       SEQ(CHAR('\\'), ALT(SEQ(CHAR('u'),
			       CHARSET(hex_digit_set), ch1 = AS_CHAR(val),
			       CHARSET(hex_digit_set), ch2 = AS_CHAR(val),
			       CHARSET(hex_digit_set), ch3 = AS_CHAR(val),
			       CHARSET(hex_digit_set), ch4 = AS_CHAR(val),
			       val = AS_VAL(((h2i(ch1) << 24) + 
					     (h2i(ch2) << 16) +
					     (h2i(ch3) << 8) +
					     h2i(ch4)))),
			   SEQ(CHAR('n'), val = AS_VAL('\n')),
			   SEQ(CHAR('r'), val = AS_VAL('\r')),
			   SEQ(CHAR('t'), val = AS_VAL('\t')),
			   // \", \\, etc.
			   ANY()
			   ));
     }
END_RULE

BEGIN_RULE(String)
{
  string_t str = string_new();

  SEQ(CHAR('"'),
      REPEAT0(ALT(SEQ(CHARSET(string_set), string_append(str, AS_CHAR(val))),
		  SEQ(Escape(), string_append(str, AS_CHAR(val))))),
      CHAR('"'));
  val = mouse_ast_new_leaf(M_STR, str);
}
END_RULE

BEGIN_RULE(Char)
{
  string_t str = string_new();
  mouse_ast_t result;

  SEQ(CHAR('\''),
      ALT(CHARSET(char_set), Escape()),
      str = string_append(str, AS_CHAR(val));
      result = mouse_ast_new_leaf(M_CHAR, str);
      CHAR('\''));
  val = result;
}
END_RULE
