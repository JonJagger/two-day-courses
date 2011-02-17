#include "calcstat.h"

void calcstat_reset(struct calcstat * stat)
{
    static const struct calcstat reset;
    *stat = reset;
}

void calcstat_update(struct calcstat * stat, int value)
{
    stat->sum += value;
    if (stat->n == 0 || value < stat->min)
        stat->min = value;
    if (stat->n == 0 || value > stat->max)
        stat->max = value;
    ++stat->n;
}
