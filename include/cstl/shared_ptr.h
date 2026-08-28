#ifndef CSTL_SHARED_PTR_H
#define CSTL_SHARED_PTR_H

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Alias for the deleter function type of a shared pointer.
 */
typedef void (*deleter_t)(void*);

/**
 * @brief A shared pointer is a smart pointer that holds a pointer to a value shared between multiple owners.
 * Each owner keeps track of the number of owners and the deleter function. When the last owner is released, the
 * value is deleted.
 */
typedef struct shared_ptr shared_ptr_t;

/**
 * @brief Creates a shared pointer from a value.
 *
 * @param data The value to create the shared pointer from.
 * @return A shared pointer to the value.
 */
shared_ptr_t* shared_ptr_make(void* data);

/**
 * @brief Creates a shared pointer from a value with a custom deleter.
 *
 * @param data The value to create the shared pointer from.
 * @param deleter The deleter function to use.
 * @return A shared pointer to the value.
 */
shared_ptr_t* shared_ptr_make_deleter(void* data, deleter_t deleter);

/**
 * @brief Clones a shared pointer.
 *
 * @param src The shared pointer to clone.
 * @return A new shared pointer that shares ownership with the original.
 */
shared_ptr_t* shared_ptr_clone(const shared_ptr_t* src);

/**
 * @brief Swaps two shared pointers.
 *
 * @param a The first shared pointer.
 * @param b The second shared pointer.
 */
void shared_ptr_swap(shared_ptr_t* a, shared_ptr_t* b);

/**
 * @brief Retrieves the data pointer from a shared pointer.
 *
 * @param src The shared pointer to retrieve the data pointer from.
 * @return The data pointer.
 */
void* shared_ptr_get(const shared_ptr_t* src);

/**
 * @brief Retrieves the deleter function from a shared pointer.
 *
 * @param src The shared pointer to retrieve the deleter function from.
 * @return The deleter function.
 */
deleter_t shared_ptr_get_deleter(const shared_ptr_t* src);

/**
 * @brief Retrieves the number of shared pointers that share ownership with a given shared pointer (including
 * the given pointer itself).
 *
 * @param src The shared pointer to retrieve the use count from.
 * @return The use count.
 */
uint32_t shared_ptr_use_count(const shared_ptr_t* src);

/**
 * @brief Releases a shared pointer.
 *
 * @param ptr The shared pointer to release.
 */
void shared_ptr_release(shared_ptr_t** ptr);

#endif
