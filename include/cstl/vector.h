#ifndef CSTL_VECTOR_H
#define CSTL_VECTOR_H

#include <stddef.h>

/**
 * @brief Alias for destructor function type for vector elements.
 */
typedef void (*destructor_t)(void*);

/**
 * @brief A vector is a dynamic array that can grow and shrink in size.
 */
typedef struct vector vector_t;

/**
 * @brief Creates a new vector with the specified element size, capacity, and destructor function.
 *
 * @param element_size The size of each element in the vector.
 * @param capacity The initial capacity of the vector.
 * @param element_destructor The destructor function for vector elements.
 * @return A pointer to the newly created vector.
 */
vector_t* vector_create(size_t element_size, size_t capacity, destructor_t element_destructor);

/**
 * @brief Clears the vector, removing all elements and resetting the size to 0.
 *
 * @param vector The vector to clear.
 */
void vector_clear(vector_t* vector);

/**
 * @brief Pushes a new element to the back of the vector.
 * Resizes the vector if necessary.
 *
 * @param vector The vector to push back into.
 * @param data The data to push back.
 * @return A pointer to the vector.
 */
vector_t* vector_push_back(vector_t* vector, const void* data);

/**
 * @brief Pops the last element from the vector.
 *
 * @param vector The vector to pop back from.
 */
void vector_pop_back(vector_t* vector);

/**
 * @brief Reserves space for a new capacity in the vector.
 *
 * @param vector The vector to reserve space for.
 * @param new_capacity The new capacity to reserve.
 * @return A pointer to the vector.
 */
vector_t* vector_reserve(vector_t* vector, size_t new_capacity);

/**
 * @brief Returns a pointer to the element at the given index.
 *
 * @param vector The vector to get the element from.
 * @param index The index of the element to get.
 * @return A pointer to the element.
 */
void* vector_at(vector_t* vector, size_t index);

/**
 * @brief Returns a pointer to the beginning of the vector.
 *
 * @param vector The vector to get the beginning from.
 * @return A pointer to the beginning of the vector.
 */
void* vector_begin(vector_t* vector);

/**
 * @brief Returns a pointer to the end of the vector.
 *
 * @param vector The vector to get the end from.
 * @return A pointer to the end of the vector.
 */
void* vector_end(vector_t* vector);

/**
 * @brief Returns the size of the vector.
 *
 * @param vector The vector to get the size from.
 * @return The size of the vector.
 */
size_t vector_get_size(const vector_t* vector);

/**
 * @brief Returns the capacity of the vector.
 *
 * @param vector The vector to get the capacity from.
 * @return The capacity of the vector.
 */
size_t vector_get_capacity(const vector_t* vector);

/**
 * @brief Destroys the vector.
 *
 * @param vector The vector to destroy.
 */
void vector_destroy(vector_t** vector);

#define vector_of(T, capacity) vector_create(sizeof(T), (capacity), NULL)
#define vector_of_destr(T, capacity, destr) vector_create(sizeof(T), (capacity), (destr))
#define vector_of_empty(T) vector_create(sizeof(T), 0, NULL)

#endif
