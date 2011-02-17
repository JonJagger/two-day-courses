#include "date2.h"
#include "cta.h"
#include <stdlib.h>
#include <stdio.h>

struct date 
{
    int year;
    int month;
    int day;
};

enum { january=1, february, march, april, may, june, 
       july, august, september, october, november, december };

COMPILE_TIME_ASSERTION(sizeof(date) <= size_of_date);

static bool is_leap_year(int year) 
{
    return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

static int days_in_month(int year, int month) 
{
    switch(month) 
    {
    case september: 
    case april: 
    case june: 
    case november:
        return 30;
    default:
        return 31;
    case february:
        return is_leap_year(year) ? 29 : 28;
    }
}

static int valid_date(int year, int month, int day) 
{
    return (year >= 0 && year < 10000) &&
           (month > 0 && month <= 12) &&
           (day > 0 && day <= days_in_month(year, month));
}

date * date_init(void * raw_mem, int year, int month, int day) 
{
    if (!valid_date(year, month, day))
        return NULL;
    else
    {
        date * when = (date *)raw_mem;
        when->year = year;
        when->month = month;
        when->day = day;

        return when;
    }
}

bool date_equal(const date * lhs, const date * rhs) 
{
    return lhs->year  == rhs->year &&
           lhs->month == rhs->month &&
           lhs->day   == rhs->day;
}

void date_print(const date * when, void print(const char *)) 
{
    char buffer[sizeof("9999-99-99")];
    snprintf(buffer, (int)sizeof(buffer), "%04d-%02d-%02d", when->year, when->month, when->day);
    print(buffer);
}
