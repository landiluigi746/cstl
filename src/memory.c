#include "cstl/memory.h"

#include "cstl/assert.h"

#include <stdint.h>
#include <stdio.h>

#define MEMSWAP_BLOCK_SIZE sizeof(size_t)

void swap_memory(void* restrict a, void* restrict b, size_t bytes)
{
    CSTL_ASSERT_DEBUG(a != NULL && b != NULL && bytes != 0,
                      "Can't swap non-existent objects or objects with a size of 0 bytes");

    if (a == b)
        return;

    uint8_t* restrict ptr_a = a;
    uint8_t* restrict ptr_b = b;
    uint8_t temp;

    while (bytes--)
    {
        temp = *ptr_a;
        *ptr_a++ = *ptr_b;
        *ptr_b++ = temp;
    }
}
