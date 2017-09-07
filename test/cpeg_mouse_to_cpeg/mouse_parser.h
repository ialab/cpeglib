#ifndef MOUSE_PARSER_H
#define MOUSE_PARSER_H

#include "mouse_tree.h"  /* for mouse_ast_t */

#define CPEG_VALUE_TYPE mouse_ast_t
#include "cpeglib.h"   /* for cpeg_value_t */

void print_mouse_ast(cpeg_value_t result, char *input, cpeg_pos_t pos, size_t size);

#endif
