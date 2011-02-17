#include "addvec.h"
#include <stdlib.h>

static void randomfill(int n, double * restrict v) 
{
    for (int i = 0; i != n; i++)
    {
        v[i] = ((double)rand()) / RAND_MAX;
    }
}

int main(void) 
{
    enum { vecsize = 512 };

    double x[vecsize];
    randomfill(vecsize, x);

    double y[vecsize];
    randomfill(vecsize, y);

    double a[vecsize];
    for (int j = 0; j != 1000; j++) 
    {
        for (int i = 0; i != vecsize; i++) 
        {
            addvec(vecsize, a, x, y);
        }
    }

    return 0;
}
