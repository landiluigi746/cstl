#ifndef CSTL_MEMORY_H
#define CSTL_MEMORY_H

#include <stddef.h>
#include <stdint.h>

void swap_memory(void* restrict a, void* restrict b, size_t bytes);

// --- ARENA ---
typedef struct arena arena_t;

arena_t* arena_create(size_t bytes);
void* arena_alloc(arena_t* arena, size_t bytes);
void arena_reset(arena_t* arena);
void arena_destroy(arena_t** arena);

#endif
