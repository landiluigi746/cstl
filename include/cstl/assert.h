#ifndef CSTL_ASSERT_H
#define CSTL_ASSERT_H

void assert_msg(int expr, const char* exprMsg, const char* msg);

#if defined(CSTL_DEBUG)
/**
 * @brief Macro for debugging assertions, enabled only in debug mode of cstl.
 *
 * @param expr The expression to assert.
 * @param msg The error message to display if the assertion fails.
 */
#define CSTL_ASSERT_DEBUG(expr, msg) assert_msg((expr), (#expr), (msg))
#else
#define CSTL_ASSERT_DEBUG(expr, msg) ((void) 0)
#endif

/**
 * @brief Macro for assertions.
 *
 * @param expr The expression to assert.
 * @param msg The error message to display if the assertion fails.
 */
#define CSTL_ASSERT(expr, msg) assert_msg((expr), (#expr), (msg))

#endif
