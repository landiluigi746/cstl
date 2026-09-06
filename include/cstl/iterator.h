#ifndef CSTL_ITERATOR_H
#define CSTL_ITERATOR_H

#include <stddef.h>

/**
 * @brief An iterator represents a position in a container and provides functions to traverse it.
 */
typedef struct iterator iterator_t;

/**
 * @brief Alias for a function pointer used to move an iterator to the next position.
 */
typedef iterator_t (*next_fn)(iterator_t);

/**
 * @brief Alias for a function pointer used to move an iterator to the previous position.
 */
typedef iterator_t (*prev_fn)(iterator_t);

/**
 * @brief Alias for a function pointer used to get the value at an iterator's position.
 */
typedef void* (*get_fn)(iterator_t);

/**
 * @brief Alias for a function pointer used to compare two iterators.
 */
typedef int (*cmp_fn)(const iterator_t, const iterator_t);

/**
 * @brief Alias for a function pointer used to get the distance between two iterators.
 */
typedef ptrdiff_t (*distance_fn)(const iterator_t, const iterator_t);

/**
 * @brief Struct holding function pointers for iterator operations.
 */
typedef struct iterator_funcs
{
    next_fn next;
    prev_fn prev;
    get_fn get;
    cmp_fn cmp;
    distance_fn distance;
} iterator_funcs_t;

/**
 * @brief The underlying struct representing an iterator.
 */
struct iterator
{
    void* context;
    void* pointer;
    const iterator_funcs_t* funcs;
};

/**
 * @brief Moves the iterator to the next position.
 *
 * @param it The iterator to move.
 */
iterator_t iterator_next(iterator_t it);

/**
 * @brief Moves the iterator to the previous position.
 *
 * @param it The iterator to move.
 */
iterator_t iterator_prev(iterator_t it);

/**
 * @brief Gets the value at the iterator's current position.
 *
 * @param it The iterator to get the value from.
 * @return The value at the iterator's current position.
 */
void* iterator_get(iterator_t it);

/**
 * @brief Compares two iterators.
 *
 * @param it1 The first iterator to compare.
 * @param it2 The second iterator to compare.
 * @return 0 if the iterators are equal, a negative value if it1 is less than it2, or a positive value if it1 is
 * greater than it2.
 */
int iterator_cmp(const iterator_t a, const iterator_t b);

/**
 * @brief Computes the distance between two iterators.
 *
 * @param it1 The first iterator.
 * @param it2 The second iterator.
 * @return The distance between the two iterators.
 */
ptrdiff_t iterator_distance(const iterator_t a, const iterator_t b);

#endif
