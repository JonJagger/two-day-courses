#include "midpoint.h"

#if defined(OBVIOUS_BUT_WRONG)

int midpoint(int first, int second)
{
    return (first + second) / 2;
}

#elif defined(OBVIOUS_FIX_BUT_WRONG)

int midpoint(int first, int second)
{
    return first / 2 + second / 2;
}

#else

int midpoint(int first, int second)
{
    return first + (second - first) / 2;
}

#endif
