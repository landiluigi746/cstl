#include "cstl/string.h"

#include "cstl/assert.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct string
{
    size_t length;
    size_t capacity;
    char data[];
};

string_t* string_create_empty(void)
{
    return string_create_from(NULL);
}

string_t* string_create_from(const char* src)
{
    size_t len = src == NULL ? 0 : strlen(src);

    string_t* str = malloc(sizeof(*str) + len + 1);
    CSTL_ASSERT(str != NULL, "Failed to allocate memory for a new string");

    str->length = len;
    str->capacity = len;

    if (len > 0)
        memcpy(str->data, src, len);

    str->data[len] = '\0';

    return str;
}

const char* string_get_cstr(const string_t* str)
{
    CSTL_ASSERT_DEBUG(str != NULL, "Can't get data pointer of a non-existent string");
    return str->data;
}

size_t string_get_length(const string_t* str)
{
    CSTL_ASSERT_DEBUG(str != NULL, "Can't get length of a non-existent string");
    return str->length;
}

void string_destroy(string_t** str)
{
    CSTL_ASSERT_DEBUG(str != NULL && *str != NULL, "Can't destroy a non-existent string");
    free(*str);
    *str = NULL;
}
