#ifndef CSTL_UTILITY_H
#define CSTL_UTILITY_H

/**
 * @brief Alias for element destructor function type.
 * It expects a pointer to the element to be destructed, and should free any resources associated with it.
 */
typedef void (*destructor_t)(void*);

#endif
