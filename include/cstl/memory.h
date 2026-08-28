#ifndef CSTL_MEMORY_H
#define CSTL_MEMORY_H

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Swaps two memory regions of the specified size.
 *
 * @param a Pointer to the first memory region.
 * @param b Pointer to the second memory region.
 * @param bytes The size of the memory regions to swap.
 */
void swap_memory(void* restrict a, void* restrict b, size_t bytes);

// --- ARENA ---

/**
 * @brief An arena is a fixed-size memory region for allocating memory.
 */
typedef struct arena arena_t;

/**
 * @brief Creates an arena with the specified size.
 *
 * @param bytes The size of the arena to create.
 * @return A pointer to the created arena.
 */
arena_t* arena_create(size_t bytes);

/**
 * @brief Allocates memory from the arena.
 *
 * @param arena The arena to allocate from.
 * @param bytes The size of the memory to allocate.
 * @return A pointer to the allocated memory.
 */
void* arena_alloc(arena_t* arena, size_t bytes);

/**
 * @brief Resets the arena to its initial state.
 *
 * @param arena The arena to reset.
 */
void arena_reset(arena_t* arena);

/**
 * @brief Destroys the arena and frees its memory.
 *
 * @param arena A pointer to the arena to destroy.
 */
void arena_destroy(arena_t** arena);

#endif
