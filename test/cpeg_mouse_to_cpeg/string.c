#include "string.h"
#include "allocate.h"
#include <stdlib.h> 		/* for free */
#include <string.h>		/* for strlen */

#define STRING_INITIAL_SIZE (10)

struct string_body {
  char *body;			// null-terminated.
  int capacity;			// size of body
  int length;			// size of the string.  body >= length + 1
};

static void assure_size(string_t string, int new_size) {
  if (string->capacity < new_size) {
    int new_capacity = string->capacity;
    while (new_capacity < new_size) {
      new_capacity *= 2;
    }
    char *value = allocate(new_capacity);
    for (int i = 0; i <= string->length; i++) {
      value[i] = string->body[i];
    }
    free(string->body);
    string->body = value;
    string->capacity = new_capacity;
  }
}

string_t string_new(void) {
  string_t value = allocate(sizeof(struct string_body));
  value->length = 0;
  value->body = allocate(STRING_INITIAL_SIZE);
  value->capacity = STRING_INITIAL_SIZE;
  return value;
}

string_t string_append(string_t string, char c) {
  assure_size(string, string->length + 1);
  string->body[string->length] = c;
  string->length++;
  string->body[string->length] = '\0';
  return string;
}

string_t string_append_all(string_t string, char *c_str) {
  int c_len = strlen(c_str);
  int i;
  assure_size(string, string->length + c_len);
  for (i = 0; i <= c_len; i++) {  // <= because we copy NUL char
    string->body[string->length + i] = c_str[i];
  }
  return string;
}

char *string_to_char_p(string_t string) {
  return string->body;
}
