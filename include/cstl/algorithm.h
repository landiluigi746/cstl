#ifndef CSTL_ALGORITHM_H
#define CSTL_ALGORITHM_H

#include "cstl/iterator.h"

#include <stddef.h>

/**
 * @brief Alias for function to apply to each element in a range with for_each.
 */
typedef void (*for_each_fn)(void*);

/**
 * @brief Applies a function to each element in the range [begin, end).
 *
 * @param begin The beginning of the range.
 * @param end The end of the range.
 * @param fn The function to apply to each element.
 */
void for_each(iterator_t begin, iterator_t end, for_each_fn fn);

/**
 * @brief Alias for comparator function.
 * It is expected to return an integer less than, equal to, or greater than zero if the first argument is found
 * to be respectively less than, equal to, or greater than the second argument.
 */
typedef int (*find_cmp_fn)(const void*, const void*);

/**
 * @brief Finds the first element in the range [begin, end) that satisfies the given comparator function.
 *
 * @param begin The beginning of the range.
 * @param end The end of the range.
 * @param data The data to compare against.
 * @param cmp_fn The comparator function.
 * @return An iterator pointing to the first element that satisfies the comparator function, or end if no such
 * element is found.
 */
iterator_t find(iterator_t begin, iterator_t end, const void* data, find_cmp_fn cmp_fn);

/**
 * @brief Counts the number of elements in the range [begin, end) that satisfy the given comparator function.
 *
 * @param begin The beginning of the range.
 * @param end The end of the range.
 * @param data The data to compare against.
 * @param cmp_fn The comparator function.
 * @return The number of elements that satisfy the comparator function.
 */
size_t count(iterator_t begin, iterator_t end, const void* data, find_cmp_fn cmp_fn);

#endif
