#ifndef CALCSTAT_INCLUDED
#define CALCSTAT_INCLUDED

struct calcstat
{
    int n;
    int sum;
    int min;
    int max;
};

/* all pointers shall not be null */
void calcstat_reset(struct calcstat *);
void calcstat_update(struct calcstat *, int);

#endif
