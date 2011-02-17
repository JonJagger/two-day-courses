#ifndef DATE_INCLUDED
#define DATE_INCLUDED

#include <stdbool.h>

struct date
{
    int year;
    int month;
    int day;
};

/* pointers shall not be null */
bool date_equal(const struct date * lhs, const struct date * rhs);
void date_print(const struct date * when); 

#endif
