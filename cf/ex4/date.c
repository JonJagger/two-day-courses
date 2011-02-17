#include "date.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct date 
{
    int year;
    int month;
    int day;
    bool allocated;
};

enum { date_pool_size = 16 };

enum { january=1, february, march, april, may, june, 
       july, august, september, october, november, december };

static date date_pool[date_pool_size];

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
           (day > 0 && day <= days_in_month(year,month));
}

date * date_create(int year, int month, int day) 
{
    if (!valid_date(year, month, day))
        return NULL;

    for (int i = 0; i != date_pool_size; i++) 
    {
        if (!date_pool[i].allocated) 
        {
            date_pool[i] = (date) 
            {
                .allocated = true,
                .year = year,
                .month = month,
                .day = day
            };
            return &date_pool[i];
        }
    }

    return NULL;
}

void date_destroy(date * d) 
{
    d->allocated = false;
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

