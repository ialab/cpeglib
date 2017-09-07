#ifndef MOUSE_TREE_H
#define MOUSE_TREE_H
#include <stdio.h>

#include "string.h"

typedef enum {
  M_DEF,			// Name '=' Choice
  M_NAME,			// [a-zA-Z][a-zA-Z0-9_]*
  M_CHOICE,			// Seq '/' Seq
  M_SEQ,			// Exp Exp*
  M_REP0,			// Exp '*'
  M_REP1,			// Exp '+'
  M_OPT,			// Exp '?'
  M_STR,			// '"' StringChars* '"'
  M_ANY,			// '_'
  M_NOT,			// '!' Exp
  M_AND,			// '&' Exp
  M_CHAR,			// 'c'
  M_CHARSET,		// '[' CharSetChar+ ']'
  M_RANGE,		// '[' CharSetChar '-' CharSetChar ']'
  M_NOTCHARSET,		// "^[" ChrSetChar+ ']'
  //M_UNTIL0,		// Exp *+ Exp  (currently expended to M_SEQ, M_REP0 etc. at parse time.)
  //M_UNTIL01,		// Exp ++ Exp
  M_TYPE_SIZE
} M_TYPE;

typedef struct M_ast *mouse_ast_t;
typedef struct M_list *mouse_list_t;
typedef struct M_list_iterator *mouse_list_iterator_t;

mouse_list_t mouse_list_new(void);
mouse_list_t mouse_list_append(mouse_list_t list, mouse_ast_t item);
mouse_ast_t mouse_list_get(mouse_list_t list, int n);
mouse_list_iterator_t mouse_list_iterator(mouse_list_t list);
int mouse_list_iterator_has_next(mouse_list_iterator_t iter);
mouse_ast_t mouse_list_iterator_next(mouse_list_iterator_t iter);
void mouse_list_iterator_free(mouse_list_iterator_t iter);

#define FOR(iter, list)						\
  mouse_list_iterator_t iter = mouse_list_iterator(list);	\
  while (mouse_list_iterator_has_next(iter))

#define DOLIST(ast, list)					\
  FOR(iter, list) {						\
  mouse_ast_t ast = mouse_list_iterator_next(iter);

#define END_DOLIST				\
  }						\
    mouse_list_iterator_free(iter);

mouse_ast_t mouse_ast_new_interior_from_list(M_TYPE type, mouse_list_t children);
mouse_ast_t mouse_ast_new_interior(M_TYPE type, ...);
static mouse_ast_t mouse_ast_new_unary(M_TYPE type, mouse_ast_t op) {
  return mouse_ast_new_interior(type, op, NULL);
}
static mouse_ast_t mouse_ast_new_binary(M_TYPE type, mouse_ast_t left, mouse_ast_t right) {
  return mouse_ast_new_interior(type, left, right, NULL);
}

mouse_ast_t mouse_ast_new_leaf(M_TYPE type, string_t string);

int mouse_ast_is_leaf(mouse_ast_t ast);
M_TYPE mouse_ast_type(mouse_ast_t ast);
string_t mouse_ast_value(mouse_ast_t leaf);
mouse_list_t mouse_ast_children(mouse_ast_t interior);

void mouse_ast_print(mouse_ast_t ast, FILE *out);

#endif
