/* bitcount_test.c */

#include "bitcount.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>

const int bits_per_int = sizeof(int) * CHAR_BIT;

void require_counts_all_bits(void)
{
    assert(bitcount(-1) == bits_per_int);
    assert(bitcount(~0) == bits_per_int);
}

void require_counts_no_bits(void)
{
    assert(bitcount(0) == 0);
}

void require_counts_one_bit(void)
{
    int one_bit = 1;
    while (one_bit != 0)
    {
        assert(bitcount(one_bit) == 1);
        one_bit <<= 1;
    }
}

void require_counts_contiguous_bits(void)
{
    for (int count = 0; count != bits_per_int; ++count)
    {
        // 00000000000000000000000      0
        // 11111111111111111111111     ~0
        // 11111111111111111110000     ~0 << 4
        // 00000000000000000001111   ~(~0 << 4)
        const int contiguous = ~0 << count;
        assert(bitcount(contiguous) == bits_per_int - count);
        assert(bitcount(~contiguous) == count);
    }
}

void require_counts_discontiguous_bits(void)
{
    assert(bitcount(5) == 2);   // 0000101
    assert(bitcount(~5) == bits_per_int - 2);

    assert(bitcount(9) == 2);   // 0001001
    assert(bitcount(~9) == bits_per_int - 2);

    assert(bitcount(17) == 2);  // 0010001
    assert(bitcount(~17) == bits_per_int - 2);

    assert(bitcount(27) == 4);  // 0011011   
    assert(bitcount(~27) == bits_per_int - 4);
}

int main(void)
{
    require_counts_all_bits();
    require_counts_no_bits();
    require_counts_one_bit();
    require_counts_contiguous_bits();
    require_counts_discontiguous_bits();
    puts("bitcount unittest OK");
    return 0;
}
