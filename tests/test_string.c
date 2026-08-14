#include "cstl/assert.h"

#include <cstl/string.h>
#include <string.h>

int main(void)
{
    string_t* str1 = string_create_from("123456789123456");
    CSTL_ASSERT(strcmp(string_get_cstr(str1), "123456789123456") == 0,
                "Stored string was expected to be \"123456789123456\"");
    CSTL_ASSERT(string_get_length(str1) == 15, "Expected string length to be 15");

    string_t* str2 = string_create_from("abcdefghijklmnopqrstuvwxyz");
    CSTL_ASSERT(strcmp(string_get_cstr(str2), "abcdefghijklmnopqrstuvwxyz") == 0,
                "Stored string was expected to be \"abcdefghijklmnopqrstuvwxyz\"");
    CSTL_ASSERT(string_get_length(str2) == 26, "Expected string length to be 26");

    string_destroy(&str1);
    string_destroy(&str2);

    return 0;
}
