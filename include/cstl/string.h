#ifndef CSTL_STRING_H
#define CSTL_STRING_H

#include <stddef.h>

/**
 * @brief This struct holds a dynamic string that can be modified and resized as needed.
 */
typedef struct string string_t;

/**
 * @brief Creates an empty string.
 *
 * @return A pointer to the newly created string.
 */
string_t* string_create_empty(void);

/**
 * @brief Creates a string from a null-terminated C string.
 *
 * @param src The null-terminated C string to copy.
 * @return A pointer to the newly created string.
 */
string_t* string_create_from(const char* src);

/**
 * @brief Clears the given string, making it empty.
 * Keeps the capacity allocated.
 *
 * @param str The string to clear.
 */
void string_clear(string_t* str);

/**
 * @brief Appends a null-terminated C string to the given string.
 *
 * @param str The string to append to.
 * @param suffix The null-terminated C string to append.
 * @return A pointer to the modified string.
 */
string_t* string_append(string_t* str, const char* suffix);

/**
 * @brief Pushes a single character to the end of the given string.
 *
 * @param str The string to push to.
 * @param c The character to push.
 * @return A pointer to the modified string.
 */
string_t* string_push_back(string_t* str, char c);

/**
 * @brief Reserves space for the given string to avoid unnecessary reallocations.
 *
 * @param str The string to reserve space for.
 * @param new_capacity The new capacity to reserve.
 * @return A pointer to the modified string.
 */
string_t* string_reserve(string_t* str, size_t new_capacity);

/**
 * @brief Returns a pointer to the null-terminated C string representation of the given string.
 *
 * @param str The string to get the C string from.
 * @return A pointer to the null-terminated C string.
 */
const char* string_get_cstr(const string_t* str);

/**
 * @brief Returns the length of the given string.
 *
 * @param str The string to get the length of.
 * @return The length of the string.
 */
size_t string_get_length(const string_t* str);

/**
 * @brief Returns the capacity of the given string.
 *
 * @param str The string to get the capacity of.
 * @return The capacity of the string.
 */
size_t string_get_capacity(const string_t* str);

/**
 * @brief Destroys the given string, freeing its memory.
 *
 * @param str The string to destroy.
 */
void string_destroy(string_t** str);

#endif
