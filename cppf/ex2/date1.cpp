#include "date1.hpp"
#include "xyzlib.h"

bool mylib_date_is_valid(const mylib_date * date)
{
    return date->month >= 1 && date->month <= 12
        && date->day >= 1
        && date->day <= xyzlib_days_in_month(date->year, date->month);
}
        
void mylib_date_offset(mylib_date * date, int days)
{
    int day_number = xyzlib_to_day_number(date->year,date->month,date->day);
    int new_day_number = day_number + days;
    xyzlib_to_ymd(new_day_number, &date->year, &date->month, &date->day);
}

int mylib_date_diff(const mylib_date * date, const mylib_date * other_date)
{
    int day_number = xyzlib_to_day_number(date->year, date->month, date->day);
    int other_day_number = xyzlib_to_day_number(
        other_date->year, other_date->month, other_date->day);
    return day_number - other_day_number;
}

bool mylib_date_is_equal(const mylib_date * date, const mylib_date * other_date)
{
    return date->year == other_date->year &&
        date->month == other_date->month &&
        date->day == other_date->day;
}
