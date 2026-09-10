#include <cstl/assert.h>
#include <cstl/forward_list.h>
#include <cstl/iterator.h>

int main(void)
{
    forward_list_t* int_list = forward_list_of(int);
    int i;

    for (i = 0; i < 10; ++i)
        int_list = forward_list_push_front(int_list, &i);

    CSTL_ASSERT((*(int*) forward_list_begin(int_list)) == 9,
                "Expected first number stored in forward list to be 9");
    forward_list_pop_front(int_list);

    iterator_t it;
    iterator_t end = forward_list_it_end(int_list);

    for (i = 8, it = forward_list_it_begin(int_list); iterator_cmp(it, end) != 0; it = iterator_next(it), --i)
    {
        int n = *(int*) iterator_get(it);
        CSTL_ASSERT(n == i, "Expected values stored in forward list to be [8..0]");
    }

    forward_list_destroy(&int_list);

    return 0;
}
