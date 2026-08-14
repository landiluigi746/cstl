#ifndef CSTL_STRING_H
#define CSTL_STRING_H

#include <stddef.h>

typedef struct string string_t;

string_t* string_create_empty(void);
string_t* string_create_from(const char* src);
const char* string_get_cstr(const string_t* str);
size_t string_get_length(const string_t* str);
void string_destroy(string_t** str);

#endif
