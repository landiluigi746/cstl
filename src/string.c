#include "cstl/string.h"

#include "cstl/assert.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_CAPACITY_GROWTH_FACTOR 3 / 2

struct string
{
    size_t length;
    size_t capacity;
    char data[];
};

static string_t* string_grow_if_necessary(string_t* str, size_t space_required)
{
    if (space_required <= str->capacity - str->length)
        return str;

    size_t new_capacity = (str->capacity + space_required) * STRING_CAPACITY_GROWTH_FACTOR;
    str = realloc(str, sizeof(*str) + new_capacity + 1);
    CSTL_ASSERT(str != NULL, "Failed to allocate memory for a string growth");

    str->capacity = new_capacity;

    return str;
}

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

void string_clear(string_t* str)
{
    CSTL_ASSERT_DEBUG(str != NULL, "Can't clear a non-existent string");
    str->length = 0;
    str->data[0] = '\0';
}

string_t* string_append(string_t* str, const char* suffix)
{
    CSTL_ASSERT_DEBUG(str != NULL, "Can't append data to a non-existent string");

    if (suffix == NULL || *suffix == '\0')
        return str;

    size_t suffix_len = strlen(suffix);
    str = string_grow_if_necessary(str, suffix_len);

    memcpy(str->data + str->length, suffix, suffix_len);
    str->length += suffix_len;
    str->data[str->length] = '\0';

    return str;
}

string_t* string_push_back(string_t* str, char c)
{
    CSTL_ASSERT_DEBUG(str != NULL, "Can't append data to a non-existent string");

    if (c == '\0')
        return str;

    str = string_grow_if_necessary(str, 1);
    str->data[str->length++] = c;
    str->data[str->length] = '\0';

    return str;
}

string_t* string_reserve(string_t* str, size_t new_capacity)
{
    CSTL_ASSERT_DEBUG(str != NULL, "Can't reserve space for a non-existent string");

    if (new_capacity <= str->capacity)
        return str;

    str = realloc(str, sizeof(*str) + new_capacity + 1);
    CSTL_ASSERT(str != NULL, "Failed to allocate memory for a string growth");

    str->capacity = new_capacity;

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

size_t string_get_capacity(const string_t* str)
{
    CSTL_ASSERT_DEBUG(str != NULL, "Can't get capacity of a non-existent string");
    return str->capacity;
}

void string_destroy(string_t** str)
{
    CSTL_ASSERT_DEBUG(str != NULL && *str != NULL, "Can't destroy a non-existent string");
    free(*str);
    *str = NULL;
}
