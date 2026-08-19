#include <cstl/assert.h>
#include <cstl/string.h>
#include <cstl/vector.h>
#include <string.h>

int main(void)
{
    vector_t* vec1 = vector_of(int, 10);

    CSTL_ASSERT(vector_get_size(vec1) == 0, "Expected vector size to be 0");
    CSTL_ASSERT(vector_get_capacity(vec1) == 10, "Expected capacity to be 10");

    int i;
    for (i = 0; i < 10; ++i)
        vec1 = vector_push_back(vec1, &i);

    CSTL_ASSERT(vector_get_size(vec1) == 10, "Expected vector size to be 10");
    CSTL_ASSERT(vector_get_capacity(vec1) == 10, "Expected vector capacity to be 10");

    for (i = 0; i < 10; ++i)
        CSTL_ASSERT(*(int*) vector_at(vec1, (size_t) i) == i, "Expected values stored in vector to be [0, 9]");

    vector_destroy(&vec1);

    vector_t* vec2 = vector_of_empty(string_t*);
    const char* strings[] = {
        "hello world!", "simple string", "btc", "roman empire", "call of duty",
    };
    const size_t len = sizeof(strings) / sizeof(strings[0]);

    for (i = 0; i < len; ++i)
    {
        string_t* str = string_create_from(strings[i]);
        vec2 = vector_push_back(vec2, &str);
    }

    CSTL_ASSERT(vector_get_size(vec2) == len, "Expected vector size to be 5");
    CSTL_ASSERT(vector_get_capacity(vec2) != len, "Expected vector capacity to be different from 5");

    for (i = 0; i < len; ++i)
    {
        string_t* str = *(string_t**) vector_at(vec2, i);
        CSTL_ASSERT(strcmp(string_get_cstr(str), strings[i]) == 0,
                    "Expected strings stored in vector to match the ones declared in the strings array");
        string_destroy(&str);
    }

    vector_destroy(&vec2);

    return 0;
}
