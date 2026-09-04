#include <cstl/algorithm.h>
#include <cstl/assert.h>
#include <cstl/iterator.h>
#include <cstl/vector.h>

void double_number(void* data)
{
    *(int*) data *= 2;
}

int cmp_int(const void* a, const void* b)
{
    return *(int*) a - *(int*) b;
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

    const int nums[] = {2, 4, 1, 7, 3, 2, 5};
    const size_t size = sizeof(nums) / sizeof(nums[0]);
    vec = vector_of(int, size);

    for (i = 0; i < (int) size; i++)
        vec = vector_push_back(vec, &nums[i]);

    iterator_t min_it = min(vector_it_begin(vec), vector_it_end(vec), &cmp_int);
    iterator_t max_it = max(vector_it_begin(vec), vector_it_end(vec), &cmp_int);

    CSTL_ASSERT(*(int*) iterator_get(min_it) == 1, "Expected smallest number to be 1");
    CSTL_ASSERT(*(int*) iterator_get(max_it) == 7, "Expected biggest number to be 7");

    CSTL_ASSERT(iterator_cmp(find(vector_it_begin(vec), vector_it_end(vec), &(int){7}, &cmp_int),
                             vector_it_end(vec)) != 0,
                "Expected 7 to be found with find()");
    CSTL_ASSERT(iterator_cmp(find(vector_it_begin(vec), vector_it_end(vec), &(int){8}, &cmp_int),
                             vector_it_end(vec)) == 0,
                "Expected 8 to be not found with find()");
    CSTL_ASSERT(count(vector_it_begin(vec), vector_it_end(vec), &(int){2}, &cmp_int) == 2,
                "Expected 2 to be found 2 times with count()");

    vector_destroy(&vec);

    return 0;
}
