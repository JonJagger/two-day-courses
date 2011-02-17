#include "calcstat.h"
#include <stdio.h>

int main(void)
{
    int value;
    struct calcstat stat;

    calcstat_reset(&stat);
    while (fscanf(stdin, "%d", &value) == 1)
    {
        calcstat_update(&stat, value);
    }

    printf("n=%d, average=%lf, min=%d, max=%d\n",
           stat.n, stat.sum / (double)stat.n, stat.min, stat.max);
    
    return 0;
}
