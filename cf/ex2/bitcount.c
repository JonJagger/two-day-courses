
#include "bitcount.h"

int bitcount(int n)
{
    int count = 0;
    while (n != 0) 
    {
        n &= (n - 1);
        count++;
    }
    return count;
}
