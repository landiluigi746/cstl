#ifndef CSTL_ASSERT_H
#define CSTL_ASSERT_H

void assert_msg(int expr, const char* exprMsg, const char* msg);

#if defined(CSTL_DEBUG)
#define CSTL_ASSERT_DEBUG(expr, msg) assert_msg((expr), (#expr), (msg))
#else
#define CSTL_ASSERT_DEBUG(expr)
#endif

#define CSTL_ASSERT(expr, msg) assert_msg((expr), (#expr), (msg))

#endif
