#include <cstl/assert.h>
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

    string_t* str3 = string_create_from("hello");
    str3 = string_append(str3, ", world");
    CSTL_ASSERT(strcmp(string_get_cstr(str3), "hello, world") == 0,
                "Stored string was expected to be \"hello, world\"");
    str3 = string_push_back(str3, '!');
    CSTL_ASSERT(strcmp(string_get_cstr(str3), "hello, world!") == 0,
                "Stored string was expected to be \"hello, world!\"");
    str3 = string_reserve(str3, 32);
    CSTL_ASSERT(string_get_capacity(str3) == 32, "Expected string capacity to be 32");
    CSTL_ASSERT(strcmp(string_get_cstr(str3), "hello, world!") == 0,
                "Stored string was expected to be \"hello, world!\"");
    str3 = string_shrink_to_fit(str3);
    CSTL_ASSERT(string_get_length(str3) == string_get_capacity(str3),
                "Expected string capacity to be equal to length");
    string_clear(str3);
    CSTL_ASSERT(strcmp(string_get_cstr(str3), "") == 0, "Stored string was expected to be \"\"");
    CSTL_ASSERT(string_get_length(str3) == 0, "Expected string length to be 0");

    string_destroy(&str3);

    return 0;
}
