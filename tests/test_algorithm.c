#include <cstl/algorithm.h>
#include <cstl/assert.h>
#include <cstl/vector.h>

void double_number(void* data)
{
    *(int*) data *= 2;
}

int main(void)
{
    vector_t* vec = vector_of(int, 10);
    int i;

    for (i = 0; i < 10; ++i)
        vec = vector_push_back(vec, &i);

    for_each(vector_it_begin(vec), vector_it_end(vec), &double_number);

    for (i = 0; i < 10; ++i)
    {
        int n = *(int*) vector_at(vec, i);
        CSTL_ASSERT(n == i * 2,
                    "Expected numbers stored in vector after doubling to be multiples of 2 up to 18");
    }

    vector_destroy(&vec);

    return 0;
}
