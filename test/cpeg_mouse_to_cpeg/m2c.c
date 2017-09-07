#include <assert.h>
#include <stdio.h>
#include <stdlib.h>		/* for exit */
#include <string.h>		/* for strlen */
#include "mouse_parser.h"
#include "mouse_tree.h"

typedef void (*print_node)(mouse_ast_t ast);

static print_node printer[M_TYPE_SIZE];

static void pp_ast(mouse_ast_t ast) {
  (*printer[mouse_ast_type(ast)])(ast);
}

static mouse_ast_t first(mouse_ast_t ast) {
  return mouse_list_get(mouse_ast_children(ast), 0);
}

static mouse_ast_t second(mouse_ast_t ast) {
  return mouse_list_get(mouse_ast_children(ast), 1);
}

static char *name_string(mouse_ast_t name) {
  assert(mouse_ast_type(name) == M_NAME);
  return string_to_char_p(mouse_ast_value(name));
}

static int current_column = 0;

static void putstr(const char *str) {
  current_column += strlen(str);
  fputs(str, stdout);
}

static void putch(char ch) {
  current_column++;
  putchar(ch);
}

static void newline(void) {
  current_column = 0;
  putchar('\n');
}

static void print_name_string(char *name_str) {
  putstr("n_");
  putstr(name_str);
}

static void print_name(mouse_ast_t name) {
  print_name_string(name_string(name));
}

static void indent_to(int col) {
  //??
  if (current_column > col) newline();
  while (current_column < col) {
    putch(' ');
  }
}

static void print_with_escape(char ch) {
  switch (ch) {
  case '\n': putch('\\'); putch('n'); break;
  case '\r': putch('\\'); putch('r'); break;
  case '\t': putch('\\'); putch('t'); break;
  case '\f': putch('\\'); putch('f'); break;
  case '\\': putch('\\'); putch('\\'); break;
  case '\'': putch('\\'); putch('\''); break;
  case '"': putch('\\'); putch('\"'); break;
    /*
      case '-': putch('\\'); putch('-'); break;
      case '[': putch('\\'); putch('['); break;
      case ']': putch('\\'); putch(']'); break;
    */
  default: putch(ch); break;
  }
}

static void print_string(string_t str) {
  putch('"');
  for (char *p = string_to_char_p(str); *p; p++) {
    print_with_escape(*p);
  }
  putch('"');
}

static void print_char(char ch) {
  putch('\'');
  print_with_escape(ch);
  putch('\'');
}

static void print_charset(M_TYPE type, string_t str) {
  if (type == M_NOTCHARSET) {
    putch('^');
  }
  putch('[');
  char *p = string_to_char_p(str);
  if (type == M_RANGE) {
    print_with_escape(p[0]);
    putch('-');
    print_with_escape(p[1]);
  } else {
    while (*p) {
      print_with_escape(*p++);
    }
  }
  putch(']');
}

static void print_prefix(char *op, mouse_ast_t ast) {
  putstr(op);
  putch('(');
  int col = current_column;
  FOR(iter, mouse_ast_children(ast)) {
    mouse_ast_t c = mouse_list_iterator_next(iter);
    indent_to(col);
    pp_ast(c);
    if (mouse_list_iterator_has_next(iter)) {
      putstr(", ");
    }
  }
  putstr(")");
}

static int list_length(mouse_list_t list) {
  int i = 0;
  DOLIST(ignore, list) i++; END_DOLIST;
  return i;
}

static mouse_ast_t shape_ast(mouse_ast_t ast) {
  /* ChoiceまたはSequenceに対して：
     ・子供の数が10を超えていたら，10までに分割する．
 */
  int len = list_length(mouse_ast_children(ast));
  if (len <= 10) {
    return ast;
  } else {
    /* 分割する */
    M_TYPE type = mouse_ast_type(ast);
    mouse_list_t new_children = mouse_list_new(); /* 新たなノードの子．何個に分かれるかはわからない． */
    mouse_list_t current_split = mouse_list_new(); /* 最大10個． */
    int i = 0;
    DOLIST(c, mouse_ast_children(ast)) {
      mouse_list_append(current_split, c);
      if (++i == 10) {
	mouse_list_append(new_children,
			  mouse_ast_new_interior_from_list(type, current_split));
	current_split = mouse_list_new();
	i = 0;
      }
    }END_DOLIST;
    if (i == 1) {
      /* 余りが1個だけなので，SEQ()やALT()で囲わない */
      mouse_list_append(new_children, mouse_list_get(current_split, 0));
    } else if (i > 1) {
      mouse_list_append(new_children,
			  mouse_ast_new_interior_from_list(type, current_split));
    }
    /* new_childrenが10を超えている可能性があるので再帰的に再度チェックする． */
    return shape_ast(mouse_ast_new_interior_from_list(type, new_children));
  }
}

static void print_prologue(void) {
  putstr("#include \"cpeglib.h\"");
  newline();  newline();
}

static void print_declare_rules(mouse_ast_t defs) {
  putstr("DECLARE_RULES(");
  int col = current_column;
  FOR(iter, mouse_ast_children(defs)) {
    mouse_ast_t def = mouse_list_iterator_next(iter);
    indent_to(col);
    print_name(first(def));
    if (mouse_list_iterator_has_next(iter)) {
      putstr(", ");
      newline();
    }
  }
  mouse_list_iterator_free(iter);
  putstr(");");
  newline();newline();
}

static mouse_list_t charsets;

static void collect_charsets(mouse_ast_t ast, mouse_list_t charsets) {
  M_TYPE type = mouse_ast_type(ast);
  if (type == M_CHARSET ||
      type == M_RANGE ||
      type == M_NOTCHARSET) {
    mouse_list_append(charsets, ast);
  } else if (! mouse_ast_is_leaf(ast)) {
    DOLIST(child, mouse_ast_children(ast))
      collect_charsets(child, charsets);
    END_DOLIST
  }
}

static int search_charset(mouse_ast_t cs) {
  assert(mouse_ast_type(cs) == M_CHARSET ||
	 mouse_ast_type(cs) == M_RANGE ||
	 mouse_ast_type(cs) == M_NOTCHARSET);
  int i = 0;
  DOLIST(elem, charsets)
    if (elem == cs) {
      return i;
    }
    i++;
  END_DOLIST
  assert(0);
}

static void print_charsets_defs(mouse_list_t charsets) {
  int i = 0;
  DOLIST(ignore, charsets)
    printf("cpeg_charset_t cs%d;\n", i++);
  END_DOLIST
  putchar('\n');
}

/* Rule定義のヘッダ部を出力する．
 quote が真なら，名前は衝突しないようプリフィックス"n_"をつける． */

static void print_rule_header(char *name, int quote) {
  putstr("BEGIN_RULE(");
  if (quote) {
    print_name_string(name);
  } else {
    putstr(name);
  }
  putstr(") {");
  newline();
}

static void print_charsets_inits(mouse_list_t charsets) {
  // rangeとlistは別のノードにする?
  static char buf[100];
  int i = 0, col = current_column;
  DOLIST(cs, charsets) {
    M_TYPE type = mouse_ast_type(cs);
    printf("\n/* cs%d:", i);
    print_charset(type, mouse_ast_value(cs));
    printf(" */");
    newline();
    char *chars = string_to_char_p(mouse_ast_value(cs));
    switch (type) {
    case M_RANGE:
      indent_to(col);
      sprintf(buf, "cs_range(cs%d, ", i);
      putstr(buf);
      print_char(chars[0]);
      putstr(", ");
      print_char(chars[1]);
      putstr(");");
      break;
    case M_CHARSET:
    case M_NOTCHARSET:
      while (*chars) {
	indent_to(col);
	sprintf(buf, "cs_simple(cs%d, ", i);
	putstr(buf);
	print_char(*chars++);
	putstr(");");
      }
      if (type == M_NOTCHARSET) {
	indent_to(col);
	sprintf(buf, "cs_complement(cs%d);", i);
      }
      break;
    default:
      assert(0);
      break;
    }
    i++;
  } END_DOLIST
  newline();
}

static void print_rule_footer(void) {
  putch('}');
  newline();
  putstr("END_RULE");
  newline(); newline();
}

static void print_start(mouse_ast_t defs, mouse_list_t charsets) {
  print_rule_header("START", false);
  putstr("  ");
  print_charsets_inits(charsets);
  indent_to(2);
  print_name(first(first(defs))); putstr("();"); newline();
  print_rule_footer();
}

static void print_DEF(mouse_ast_t def) {
  print_rule_header(name_string(first(def)), true);
  putstr("  ");
  pp_ast(second(def));
  putstr(";");
  newline();
  print_rule_footer();
}

static void print_NAME(mouse_ast_t ast) {
  print_name(ast);
  putstr("()");
}

static void print_prefix_optimized(char *op, mouse_ast_t ast) {
  int len = list_length(mouse_ast_children(ast));
  if (len == 1) {
    pp_ast(first(ast));
  } else {
    print_prefix(op, shape_ast(ast));
  }
}

static void print_CHOICE(mouse_ast_t ast) {
  print_prefix_optimized("ALT", ast);
}

static void print_SEQ(mouse_ast_t ast) {
  print_prefix_optimized("SEQ", ast);
}

static void print_REP0(mouse_ast_t ast) {
  print_prefix("REPEAT0", ast);
}

static void print_REP1(mouse_ast_t ast) {
  print_prefix("REPEAT1", ast);
}

static void print_OPT(mouse_ast_t ast) {
  print_prefix("OPTION", ast);
}

static void print_STR(mouse_ast_t ast) {
  putstr("STR(");
  print_string(mouse_ast_value(ast));
  putstr(")");
}

static void print_ANY(mouse_ast_t ast) {
  putstr("ANY()");
}

static void print_NOT(mouse_ast_t ast) {
  print_prefix("NOTPRE", ast);
}

static void print_AND(mouse_ast_t ast) {
  print_prefix("ANDPRE", ast);
}

static void print_CHAR(mouse_ast_t ast) {
  putstr("CHAR(");
  print_char(string_to_char_p(mouse_ast_value(ast))[0]);
  putstr(")");
}

static void print_CHARSET(mouse_ast_t ast) {
  static char buf[40];
  int i = search_charset(ast);
  sprintf(buf, "CHARSET(cs%d)", i);
  putstr(buf);
}

static void print_rule_bodys(mouse_ast_t defs) {
  DOLIST(def, mouse_ast_children(defs))
    pp_ast(def);
  END_DOLIST
}

static void print_main(void) {
  putstr("int main(int argc, char *argv[]) {"); newline();
  putstr("  return cpeg_main(argc, argv);"); newline();
  putstr("}"); newline();
}

static void process(mouse_ast_t result, char *input, cpeg_pos_t pos, size_t size) {
  if (pos != size) {
    fprintf(stderr, "Parse error near position %d\n", pos);
    int start = (pos < 100 ? pos : pos - 100),
      end = (size < pos + 100 ? size : pos + 100);
    for (int i = start; i < end; i++) {
      if (i == pos) {
	fprintf(stderr, ">>>HERE<<<");
      }
      putc(input[i], stderr);
    }
    putc('\n', stderr);
    exit(1);
  }

  print_prologue();
  print_declare_rules(result);
  charsets = mouse_list_new();
  collect_charsets(result, charsets);
  print_charsets_defs(charsets);
  print_start(result, charsets);
  print_rule_bodys(result);
  print_main();
}

int main(int argc, char *argv[]) {
  printer[M_DEF] = &print_DEF;	// Name '=' Choice
  printer[M_NAME] = &print_NAME; // [a-zA-Z][a-zA-Z0-9_]*
  printer[M_CHOICE] = &print_CHOICE; // Seq '/' Seq
  printer[M_SEQ] = &print_SEQ;	     // Exp Exp*
  printer[M_REP0] = &print_REP0;     // Exp '*'
  printer[M_REP1] = &print_REP1;     // Exp '+'
  printer[M_OPT] = &print_OPT;	     // Exp '?'
  printer[M_STR] = &print_STR;	     // '"' StringChars* '"'
  printer[M_ANY] = &print_ANY;	     // '_'
  printer[M_NOT] = &print_NOT;	     // '!' Exp
  printer[M_AND] = &print_AND;	     // '&' Exp
  printer[M_CHAR] = &print_CHAR;     // 'c'
  printer[M_CHARSET] = &print_CHARSET; // '[' ChrSetChar+ ']'
  printer[M_RANGE] = &print_CHARSET; // '[' CharSetChar '-' CharSetChar ']'
  printer[M_NOTCHARSET] = &print_CHARSET; // "^[" ChrSetChar+ ']'

  return cpeg_main2(argc, argv, &process);
}
