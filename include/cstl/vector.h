#ifndef CSTL_VECTOR_H
#define CSTL_VECTOR_H

#include <stddef.h>

typedef void (*destructor_t)(void*);
typedef struct vector vector_t;

vector_t* vector_create(size_t element_size, size_t capacity, destructor_t element_destructor);
void vector_clear(vector_t* vector);
vector_t* vector_push_back(vector_t* vector, const void* data);
void vector_pop_back(vector_t* vector);
vector_t* vector_reserve(vector_t* vector, size_t new_capacity);
void* vector_at(vector_t* vector, size_t index);
void* vector_begin(vector_t* vector);
void* vector_end(vector_t* vector);
size_t vector_get_size(const vector_t* vector);
size_t vector_get_capacity(const vector_t* vector);
void vector_destroy(vector_t** vector);

#define vector_of(T, capacity) vector_create(sizeof(T), (capacity), NULL)
#define vector_of_destr(T, capacity, destr) vector_create(sizeof(T), (capacity), (destr))
#define vector_of_empty(T) vector_create(sizeof(T), 0, NULL)

#endif
