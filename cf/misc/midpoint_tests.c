#include "midpoint.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>

void require_that_midpoint_of_equal_arguments_is_the_same()
{
    assert(midpoint(1, 1) == 1);
    assert(midpoint(0, 0) == 0);
    assert(midpoint(-1, -1) == -1);
}

void require_that_midpoint_of_even_summed_arguments_involves_no_rounding()
{
    assert(midpoint(7, 13) == 10);
    assert(midpoint(2, 4) == 3);
    assert(midpoint(-7, -13) == -10);
}

void require_that_midpoint_of_odd_summed_arguments_involves_rounding()
{
    assert(midpoint(7, 14) == 10);
    assert(midpoint(2, 5) == 3);
    assert(midpoint(-7, -14) == -10);
}

void require_that_argument_ordering_does_not_affect_midpoint()
{
    assert(midpoint(8, 14) == 11);
    assert(midpoint(14, 8) == 11);
    assert(midpoint(-14, 8) == -3);
    assert(midpoint(8, -14) == -3);
}

void require_that_midpoint_of_overflowing_summed_arguments_is_defined()
{
    assert(midpoint(INT_MAX - 20, INT_MAX - 10) == INT_MAX - 15);
    assert(midpoint(INT_MAX, INT_MAX) == INT_MAX);
    assert(midpoint(INT_MIN, INT_MIN) == INT_MIN);
    assert(midpoint(INT_MIN + 20, INT_MIN + 10) == INT_MIN + 15);
    assert(midpoint(INT_MIN + 10, INT_MIN + 20) == INT_MIN + 15);
}

typedef void (*test_case)(void);

const test_case test_suite[] =
{
    require_that_midpoint_of_equal_arguments_is_the_same,
    require_that_midpoint_of_even_summed_arguments_involves_no_rounding,
    require_that_midpoint_of_odd_summed_arguments_involves_rounding,
    require_that_argument_ordering_does_not_affect_midpoint,
    require_that_midpoint_of_overflowing_summed_arguments_is_defined,
    0
};

int main()
{
    for(int test = 0; test_suite[test] != 0; ++test)
    {
        fprintf(stderr, "Test %i: ", test);
        test_suite[test]();
        fputs("OK\n", stderr);
    }
    return 0;
}
