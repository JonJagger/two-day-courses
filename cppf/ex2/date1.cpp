#include "date1.hpp"

static bool is_leap_year(int year)
{
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

static int days_in_month(int year, int month)
{
    switch (month) {
    case 2:
        return is_leap_year(year) ? 29 : 28;
    case 4: case 6: case 9: case 11:
        return 30;
    }
    return 31;
}

static int to_day_number(const mylib_date * date)
{
    int a = (14-date->month)/12;
    int y = date->year + 4800 - a;
    int m = date->month + 12*a - 3;
    int d = date->day + ((153*m+2)/5) + 365*y
        + (y/4) - (y/100) + (y/400) - 32045;
    return d;
}

static mylib_date to_ymd(int day_number)
{
    int a = day_number + 32044;
    int b = (4*a + 3)/146097;
    int c = a-((146097*b)/4);
    int d = (4*c + 3)/1461;
    int e = c - (1461*d)/4;
    int m = (5*e + 2)/153;
    mylib_date date;
    date.year = 100*b + d - 4800 + (m/10);
    date.month = m + 3 - 12 * (m/10);
    date.day = e - ((153*m + 2)/5) + 1;
    return date;
}

bool mylib_date_is_valid(const mylib_date * date)
{
    return date->month >= 1 && date->month <= 12
        && date->day >= 1
        && date->day <= days_in_month(date->year, date->month);
}
        
void mylib_date_offset(mylib_date * date, int days)
{
    *date = to_ymd(to_day_number(date) + days);
}

int mylib_date_diff(const mylib_date * date, const mylib_date * other_date)
{
    return to_day_number(date) - to_day_number(other_date);
}

bool mylib_date_is_equal(const mylib_date * date, const mylib_date * other_date)
{
    return date->year == other_date->year &&
        date->month == other_date->month &&
        date->day == other_date->day;
}
