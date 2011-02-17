#include "addvec.h"

void addvec(int n, double * restrict a, const double * restrict x, const double * restrict y) 
{
    for (int i = 0; i != n; i++)
    {
        a[i] = x[i] + y[i];
    }
}
