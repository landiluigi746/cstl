#include "cstl/algorithm.h"

#include "cstl/assert.h"
#include "cstl/iterator.h"

void for_each(iterator_t begin, iterator_t end, for_each_fn fn)
{
    CSTL_ASSERT_DEBUG(fn != NULL, "Can't execute a non-existent function");

    for (; iterator_cmp(begin, end) != 0; begin = iterator_next(begin))
        fn(begin.pointer);
}

iterator_t find(iterator_t begin, iterator_t end, const void* data, alg_cmp_fn cmp_fn)
{
    CSTL_ASSERT_DEBUG(cmp_fn != NULL, "Can't execute a non-existent function");

    for (; iterator_cmp(begin, end) != 0; begin = iterator_next(begin))
        if (cmp_fn(begin.pointer, data) == 0)
            return begin;

    return end;
}

size_t count(iterator_t begin, iterator_t end, const void* data, alg_cmp_fn cmp_fn)
{
    CSTL_ASSERT_DEBUG(cmp_fn != NULL, "Can't execute a non-existent function");

    size_t n = 0;

    for (; iterator_cmp(begin, end) != 0; begin = iterator_next(begin))
        if (cmp_fn(begin.pointer, data) == 0)
            ++n;

    return n;
}

iterator_t min(iterator_t begin, iterator_t end, alg_cmp_fn cmp_fn)
{
    CSTL_ASSERT_DEBUG(cmp_fn != NULL, "Can't execute a non-existent function");

    if (iterator_cmp(begin, end) == 0)
        return end;

    iterator_t min_it = begin;

    for (begin = iterator_next(begin); iterator_cmp(begin, end) != 0; begin = iterator_next(begin))
        if (cmp_fn(begin.pointer, min_it.pointer) < 0)
            min_it = begin;

    return min_it;
}

iterator_t max(iterator_t begin, iterator_t end, alg_cmp_fn cmp_fn)
{
    CSTL_ASSERT_DEBUG(cmp_fn != NULL, "Can't execute a non-existent function");

    if (iterator_cmp(begin, end) == 0)
        return end;

    iterator_t max_it = begin;

    for (begin = iterator_next(begin); iterator_cmp(begin, end) != 0; begin = iterator_next(begin))
        if (cmp_fn(begin.pointer, max_it.pointer) > 0)
            max_it = begin;

    return max_it;
}
