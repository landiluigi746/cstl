#include "cstl/iterator.h"

#include "cstl/assert.h"

#include <stddef.h>

iterator_t iterator_next(iterator_t it)
{
    CSTL_ASSERT_DEBUG(it.funcs != NULL, "Can't move an iterator without operations to next position");
    CSTL_ASSERT_DEBUG(it.funcs->next != NULL, "Can't move a non-forward iterator to next position");
    return it.funcs->next(it);
}

iterator_t iterator_prev(iterator_t it)
{
    CSTL_ASSERT_DEBUG(it.funcs != NULL, "Can't move an iterator without operations to prev position");
    CSTL_ASSERT_DEBUG(it.funcs->prev != NULL, "Can't move a non-bidirectional iterator to prev position");
    return it.funcs->prev(it);
}

void* iterator_get(iterator_t it)
{
    CSTL_ASSERT_DEBUG(it.funcs != NULL, "Can't get pointer from an iterator without operations");
    CSTL_ASSERT_DEBUG(it.funcs->get != NULL, "Can't get pointer from an iterator without get operation");
    return it.funcs->get(it);
}

int iterator_cmp(const iterator_t a, const iterator_t b)
{
    CSTL_ASSERT_DEBUG(a.funcs != NULL && b.funcs != NULL, "Can't compare iterators without operations");
    CSTL_ASSERT_DEBUG(a.funcs->cmp != NULL && a.funcs->cmp == b.funcs->cmp,
                      "Can't compare iterators with different comparison functions");
    return a.funcs->cmp(a, b);
}

ptrdiff_t iterator_distance(const iterator_t a, const iterator_t b)
{
    CSTL_ASSERT_DEBUG(a.funcs != NULL && b.funcs != NULL,
                      "Can't compute distance between iterators without operations");
    CSTL_ASSERT_DEBUG(a.funcs->distance != NULL && a.funcs->distance == b.funcs->distance,
                      "Can't compute distance between iterators with different functions");
    return a.funcs->distance(a, b);
}
