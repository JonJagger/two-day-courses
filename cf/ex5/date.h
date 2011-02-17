#ifndef DATE_INCLUDED
#define DATE_INCLUDED

#include "aligned.h"
#include <stdbool.h>

struct date
{
    union
    {
        union aligned correctly;
        unsigned char bytes[12];
    } shadow;
};
typedef struct date date;

bool date_init(date *, int year, int month, int day);
bool date_equal(const date *, const date *);
void date_print(const date *, void printer(const char *));
int  date_year(const date *);
int  date_month(const date *);
int  date_day(const date *);

#endif
