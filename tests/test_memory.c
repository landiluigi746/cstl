#include <cstl/assert.h>
#include <cstl/memory.h>

int main(void)
{
    int a = 42;
    int b = 64;

    swap_memory(&a, &b, sizeof(int));
    CSTL_ASSERT(a == 64 && b == 42, "Expected values to be swapped");

    int array_a[] = {0, 1, 2, 3, 4};
    int array_b[] = {5, 6, 7, 8, 9};
    swap_memory(&array_a, &array_b, sizeof(array_a));
    CSTL_ASSERT(array_a[0] == 5 && array_a[4] == 9 && array_b[0] == 0 && array_b[4] == 4,
                "Expected values in arrays to be swapped");

    return 0;
}
