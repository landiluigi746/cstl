#include <cstl/assert.h>
#include <cstl/iterator.h>
#include <cstl/string.h>
#include <cstl/vector.h>

int main(void)
{
    vector_t* int_vec = vector_of(int, 10);
    int i;

    for (i = 0; i < 10; ++i)
        int_vec = vector_push_back(int_vec, &i);

    iterator_t it;
    iterator_t end = vector_it_end(int_vec);

    for (i = 0, it = vector_it_begin(int_vec); iterator_cmp(it, end) != 0; ++i, it = iterator_next(it))
    {
        int n = *(int*) iterator_get(it);
        CSTL_ASSERT(n == i, "Expected iterated numbers to be [0, 9]");
    }

    vector_destroy(&int_vec);

    const char* src = "hello world";
    string_t* str = string_create_from(src);

    end = string_it_end(str);

    for (i = 0, it = string_it_begin(str); iterator_cmp(it, end) != 0; ++i, it = iterator_next(it))
    {
        char c = *(char*) iterator_get(it);
        CSTL_ASSERT(c == src[i], "Expected iterated characters to match original string");
        CSTL_ASSERT(iterator_distance(it, string_it_begin(str)) == i,
                    "Expected distance between iterator and begin to match character index");
    }

    it = iterator_advance(string_it_begin(str), 1);
    CSTL_ASSERT(*(char*) iterator_get(it) == src[1],
                "Expected character pointed to by iterator to be the second character of 'hello world'");

    it = iterator_advance(it, -1);
    CSTL_ASSERT(*(char*) iterator_get(it) == src[0],
                "Expected character pointed to by iterator to be the first character of 'hello world'");

    string_destroy(&str);

    return 0;
}
