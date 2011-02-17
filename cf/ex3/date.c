#include "date.h"
#include <stdio.h>

typedef struct date date;

bool date_equal(const date * lhs, const date * rhs) 
{
    return lhs->year  == rhs->year &&
           lhs->month == rhs->month &&
           lhs->day   == rhs->day;
}

void date_print(const date * when) 
{
    printf("%04d-%02d-%02d\n", when->year, when->month, when->day);
}
