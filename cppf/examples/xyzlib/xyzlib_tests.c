#include "xyzlib.h"
#include <assert.h>

int main(void)
{
    assert( xyzlib_days_in_month(2011,1) == 31);
    assert( xyzlib_days_in_month(2011,2) == 28);
    assert( xyzlib_days_in_month(2011,3) == 31);
    assert( xyzlib_days_in_month(2011,4) == 30);
    assert( xyzlib_is_leap_year(2011) == false);

    assert( xyzlib_is_leap_year(2000) == true);
    assert( xyzlib_days_in_month(2000,2) == 29);

    int day_number = xyzlib_to_day_number(2000,2,29);
    int year, month, day;
    xyzlib_to_ymd(day_number, &year, &month, &day);
    assert(year == 2000 && month == 2 && day == 29);
    day_number++;
    xyzlib_to_ymd(day_number, &year, &month, &day);
    assert(year == 2000 && month == 3 && day == 1);

    assert(xyzlib_to_day_number(2099,12,31) -
           xyzlib_to_day_number(1900,1,1) == 73048);
}
