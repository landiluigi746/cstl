#ifndef CSTL_FORWARD_LIST_H
#define CSTL_FORWARD_LIST_H

#include "cstl/iterator.h"
#include "cstl/utility.h"

#include <stddef.h>

typedef struct forward_list forward_list_t;

/**
 * @brief Creates a new forward list with the given element size and destructor.
 *
 * @param element_size The size of each element in the list.
 * @param element_destructor The destructor function for each element.
 * @return A pointer to the newly created forward list.
 */
forward_list_t* forward_list_create(size_t element_size, destructor_t element_destructor);

/**
 * @brief Clears the forward list, freeing all elements and the list itself.
 *
 * @param list The forward list to clear.
 */
void forward_list_clear(forward_list_t* list);

/**
 * @brief Pushes a new element to the front of the forward list.
 *
 * @param list The forward list to push the element into.
 * @param data The data to push into the list.
 * @return A pointer to the updated forward list.
 */
forward_list_t* forward_list_push_front(forward_list_t* list, const void* data);

/**
 * @brief Pops the front element from the forward list.
 *
 * @param list The forward list to pop the element from.
 */
void forward_list_pop_front(forward_list_t* list);

/**
 * @brief Returns a pointer to the beginning of the forward list.
 *
 * @param list The forward list to get the beginning of.
 * @return A pointer to the beginning of the forward list.
 */
void* forward_list_begin(forward_list_t* list);

/**
 * @brief Returns a pointer to the end of the forward list.
 *
 * @param list The forward list to get the end of.
 * @return A pointer to the end of the forward list.
 */
void* forward_list_end(forward_list_t* list);

/**
 * @brief Returns an iterator to the beginning of the forward list.
 *
 * @param list The forward list to get the iterator for.
 * @return An iterator to the beginning of the forward list.
 */
iterator_t forward_list_it_begin(const forward_list_t* list);

/**
 * @brief Returns an iterator to the end of the forward list.
 *
 * @param list The forward list to get the iterator for.
 * @return An iterator to the end of the forward list.
 */
iterator_t forward_list_it_end(const forward_list_t* list);

/**
 * @brief Destroys the forward list, freeing all elements and the list itself.
 *
 * @param list The forward list to destroy.
 */
void forward_list_destroy(forward_list_t** list);

/**
 * @brief Creates a forward list of the given type, with no element destructor.
 *
 * @param T The type of the elements in the forward list.
 * @return A pointer to the newly created forward list.
 */
#define forward_list_of(T) forward_list_create(sizeof(T), NULL)

/**
 * @brief Creates a forward list of the given type, with the given element destructor.
 *
 * @param T The type of the elements in the forward list.
 * @param destr The destructor for the elements in the forward list.
 * @return A pointer to the newly created forward list.
 */
#define forward_list_of_destr(T, destr) forward_list_create(sizeof(T), destr)

#endif
