#ifndef STRING_H
#define STRING_H

typedef struct string_body *string_t;

string_t string_new(void);
string_t string_append(string_t string, char c);
string_t string_append_all(string_t string, char *c_str);
char *string_to_char_p(string_t string);

#endif
