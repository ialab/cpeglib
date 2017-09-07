#include <stdlib.h>
#include <stdarg.h>

#include "mouse_tree.h"
#include "allocate.h"		/* for allocate */
#include "string.h"

struct M_list_node {
  mouse_ast_t element;
  struct M_list_node *next;
};

struct M_list {
  // empty iff (head == tail)
  // *head contains node in which element field is never used
  struct M_list_node *head, *tail;  
};

struct M_ast {
  M_TYPE type;
  union {
    string_t value;
    mouse_list_t children;
  } body;
};

static struct M_list_node *mouse_list_new_node(mouse_ast_t item) {
  struct M_list_node *value = allocate(sizeof(struct M_list_node));
  value->element = item;
  value->next = NULL;
  return value;
}

mouse_list_t mouse_list_new(void) {
  mouse_list_t value = allocate(sizeof(struct M_list));
  struct M_list_node *dummy = mouse_list_new_node(NULL);
  value->head = value->tail = dummy;
  return value;
}

mouse_list_t mouse_list_append(mouse_list_t list, mouse_ast_t item) {
  list->tail->next = mouse_list_new_node(item);
  list->tail = list->tail->next;
  return list;
}

mouse_ast_t mouse_list_get(mouse_list_t list, int n) {
  struct M_list_node *p = list->head; /* ダミーヘッダを指す */
  if (n < 0) {
    fprintf(stderr, "internal error: list index %d\n", n);
    exit(1);
  }
  while (n-- >= 0) {		/* 0番目の子ども == 最初の子ども == ダミーの次 */
    if (p == list->tail) {
      fprintf(stderr, "internal error: list out of range\n");
      exit(1);
    }
    p = p->next;
  }
  return p->element;
}

struct M_list_iterator {
  mouse_list_t list;
  struct M_list_node *current;
};

mouse_list_iterator_t mouse_list_iterator(mouse_list_t list) {
  mouse_list_iterator_t result = allocate(sizeof(struct M_list_iterator));
  result->list = list;
  result->current = list->head;

  return result;
}

int mouse_list_iterator_has_next(mouse_list_iterator_t iter) {
  return iter->current != iter->list->tail;
}

mouse_ast_t mouse_list_iterator_next(mouse_list_iterator_t iter) {
  iter->current = iter->current->next;
  return iter->current->element;
}

void mouse_list_iterator_free(mouse_list_iterator_t iter) {
  free(iter);
}

mouse_ast_t mouse_ast_new_interior_from_list(M_TYPE type, mouse_list_t children) {
  mouse_ast_t value = allocate(sizeof(struct M_ast));
  value->type = type;
  value->body.children = children;
  return value;
}

mouse_ast_t mouse_ast_new_interior(M_TYPE type, ...) {
  va_list ap;
  
  mouse_ast_t value = allocate(sizeof(struct M_ast));
  value->type = type;
  value->body.children = mouse_list_new();
  va_start(ap, type);
  mouse_ast_t v;
  for (v = va_arg(ap, mouse_ast_t); v != NULL; v = va_arg(ap, mouse_ast_t)) {
    value->body.children = mouse_list_append(value->body.children, v);
  }
  return value;
}

mouse_ast_t mouse_ast_new_leaf(M_TYPE type, string_t leaf_value) {
  mouse_ast_t value = allocate(sizeof(struct M_ast));
  value->type = type;
  value->body.value = leaf_value;
  return value;
}

int mouse_ast_is_leaf(mouse_ast_t ast) {
  switch (ast->type) {
  case M_NAME:
  case M_STR:
  case M_ANY:
  case M_CHAR:
  case M_CHARSET:
    return 1;
  default:
    return 0;
  }
}

string_t mouse_ast_value(mouse_ast_t leaf) {
  return leaf->body.value;
}

mouse_list_t mouse_ast_children(mouse_ast_t interior) {
  return interior->body.children;
}

M_TYPE mouse_ast_type(mouse_ast_t ast) {
  return ast->type;
}

static char* node_names[] = {
  // 順序は，enum の宣言と一致していなければならない．
  "Define",
  "Name",
  "Choice",
  "Sequence",
  "Repeat0",
  "Repeat1",
  "Option",
  "String",
  "Any",
  "Not",
  "And",
  "Char",
  "CharSet",
  "Range",
  "NotCharSet",
  //"Until0",
  //"Until1"
};

static void indent(int n, FILE *out) {
  while (n-- > 0) {
    putc(' ', out);
  }
}

static void pp(int level, mouse_ast_t ast, FILE *out) {
  if (mouse_ast_is_leaf(ast)) {
    fprintf(out, "%s[%s]", node_names[ast->type], string_to_char_p(ast->body.value));
  } else {
    mouse_list_t list = mouse_ast_children(ast);
    fprintf(out, "%s(", node_names[ast->type]);

    mouse_list_iterator_t iter = mouse_list_iterator(list);
    while (mouse_list_iterator_has_next(iter)) {
      putc('\n', out);
      indent(level + 2, out);
      pp(level + 2, mouse_list_iterator_next(iter), out);
      if (mouse_list_iterator_has_next(iter)) putc(',', out);
    }
    putc(')', out);
  }
}

void mouse_ast_print(mouse_ast_t ast, FILE *out) {
  pp(0, ast, out);
}
