#include "cstl/memory.h"

#include "cstl/assert.h"

#include <stdint.h>
#include <stdlib.h>

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

// --- ARENA ---
struct arena
{
    size_t offset;
    size_t capacity;
    uint8_t data[];
};

#define ARENA_ALIGNMENT sizeof(void*)

arena_t* arena_create(size_t bytes)
{
    CSTL_ASSERT_DEBUG(bytes != 0, "Can't create an arena of 0 bytes");

    arena_t* arena = malloc(sizeof(*arena) + bytes);
    CSTL_ASSERT(arena != NULL, "Failed to allocate memory for a new arena");

    arena->offset = 0;
    arena->capacity = bytes;

    return arena;
}

void* arena_alloc(arena_t* arena, size_t bytes)
{
    CSTL_ASSERT_DEBUG(arena != NULL, "Can't allocate memory from a non-existent arena");
    CSTL_ASSERT_DEBUG(bytes <= arena->capacity - arena->offset, "Exceeded maximum available space in arena");

    if (bytes == 0)
        return NULL;

    size_t aligned_offset = (arena->offset + ARENA_ALIGNMENT - 1) & ~(ARENA_ALIGNMENT - 1);
    CSTL_ASSERT_DEBUG(bytes <= arena->capacity - aligned_offset, "Exceeded maximum available space in arena");
    arena->offset = aligned_offset + bytes;

    return arena->data + aligned_offset;
}

void arena_reset(arena_t* arena)
{
    CSTL_ASSERT_DEBUG(arena != NULL, "Can't reset a non-existent arena");
    arena->offset = 0;
}

void arena_destroy(arena_t** arena)
{
    CSTL_ASSERT_DEBUG(arena != NULL && *arena != NULL, "Can't destroy a non-existent arena");
    free(*arena);
    *arena = NULL;
}
