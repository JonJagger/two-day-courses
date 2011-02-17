#include "date.h"
#include "cta.h"
#include <stdio.h>
#include <string.h>

struct shadowed_date
{
    int year;
    int month;
    int day;
};

typedef struct shadowed_date shadowed_date;

enum { january=1, february, march, april, may, june, 
       july, august, september, october, november, december };

COMPILE_TIME_ASSERTION(date, sizeof(date) >= sizeof(shadowed_date));
COMPILE_TIME_ASSERTION(date, sizeof(shadowed_date) >= sizeof(union aligned));

static bool is_leap_year(int year) 
{
    return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

static int days_in_month(int year, int month) 
{
	// thirty days hath september, april, june, and november;
	// all the rest have 31, except for february alone, which....
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
    return year >= 0 && year < 10000 &&
           month > 0 && month <= 12 &&
           day > 0 && day <= days_in_month(year, month);
}

static void date_memcpy_in(date * lhs, const shadowed_date * rhs)
{
	memcpy(lhs, rhs, sizeof(*rhs));
}

static void date_memcpy_out(shadowed_date * lhs, const date * rhs)
{
	memcpy(lhs, rhs, sizeof(*lhs));
}

bool date_init(date * shadow, int year, int month, int day) 
{
    if (valid_date(year, month, day))
    {   
        shadowed_date when = { year, month, day };
		date_memcpy_in(shadow, &when);
        return true;
    }
    else
        return false;
}

bool date_equal(const date * lhs_shadow, const date * rhs_shadow) 
{
    shadowed_date lhs, rhs;
	date_memcpy_out(&lhs, lhs_shadow);
	date_memcpy_out(&rhs, rhs_shadow);

    return lhs.year  == rhs.year &&
           lhs.month == rhs.month &&
           lhs.day   == rhs.day;
}

void date_print(const date * shadow, void print(const char *)) 
{
    shadowed_date when;
	date_memcpy_out(&when, shadow);
    char buffer[sizeof("9999/99/99")];
    snprintf(buffer, sizeof(buffer), "%04d/%02d/%02d", 
        when.year, when.month, when.day);
    print(buffer);
}

static const shadowed_date * un(const date * shadow)
{
	return (const shadowed_date *)shadow;
}

int date_year(const date * shadow)
{
    return un(shadow)->year;
}

int date_month(const date * shadow)
{    
    return un(shadow)->month;
}

int date_day(const date * shadow)
{
    return un(shadow)->day;
}

