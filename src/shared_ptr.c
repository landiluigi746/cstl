#include "cstl/shared_ptr.h"

#include "cstl/assert.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct control_block
{
    uint32_t reference_count;
    void* data;
} control_block_t;

struct shared_ptr
{
    control_block_t* control_block;
};

shared_ptr_t* shared_ptr_make(void* data)
{
    CSTL_ASSERT_DEBUG(data != NULL, "Data to construct a shared pointer from can't be NULL");

    shared_ptr_t* sptr = malloc(sizeof(*sptr));
    CSTL_ASSERT(sptr != NULL, "Failed to allocate memory for a shared pointer");

    sptr->control_block = malloc(sizeof(*sptr->control_block));
    CSTL_ASSERT(sptr->control_block != NULL,
                "Failed to allocate memory for the control block of a shared pointer");

    sptr->control_block->data = data;
    sptr->control_block->reference_count = 1;

    return sptr;
}

shared_ptr_t* shared_ptr_clone(const shared_ptr_t* src)
{
    CSTL_ASSERT_DEBUG(src != NULL && src->control_block != NULL, "Can't clone a non-existent shared pointer");

    shared_ptr_t* clone = malloc(sizeof(*clone));
    CSTL_ASSERT(clone != NULL, "Failed to allocate memory for a shared pointer");

    clone->control_block = src->control_block;
    ++clone->control_block->reference_count;

    return clone;
}

void* shared_ptr_get(shared_ptr_t* src)
{
    CSTL_ASSERT_DEBUG(src != NULL && src->control_block != NULL,
                      "Can't retrieve pointer data from a non-existent shared pointer");
    return src->control_block->data;
}

uint32_t shared_ptr_use_count(const shared_ptr_t* src)
{
    CSTL_ASSERT_DEBUG(src != NULL && src->control_block != NULL,
                      "Can't retrieve reference count from a non-existent shared pointer");
    return src->control_block->reference_count;
}

void shared_ptr_release(shared_ptr_t** ptr)
{
    CSTL_ASSERT_DEBUG(ptr != NULL && *ptr != NULL, "Can't release a non-existent shared pointer");

    shared_ptr_t* sptr = *ptr;

    if (sptr->control_block->reference_count == 1)
    {
        free(sptr->control_block->data);
        free(sptr->control_block);
    }
    else
        --sptr->control_block->reference_count;

    free(sptr);
    *ptr = NULL;
}
