#include "cstl/assert.h"

#include <stdio.h>
#include <stdlib.h>

void assert_msg(int expr, const char* exprMsg, const char* msg)
{
    if (!expr)
    {
        fprintf(stderr, "Assertion failed: %s\nError message: %s\n", exprMsg, msg);
        abort();
    }
}
