#include "date2.hpp"

namespace {
    bool is_leap_year(int year)
    {
        return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
    }

    int days_in_month(int year, int month)
    {
        switch (month) {
        case 2:
            return is_leap_year(year) ? 29 : 28;
        case 4: case 6: case 9: case 11:
            return 30;
        }
        return 31;
    }

    int to_day_number(const mylib::date * date)
    {
        int a = (14-date->month)/12;
        int y = date->year + 4800 - a;
        int m = date->month + 12*a - 3;
        int d = date->day + ((153*m+2)/5) + 365*y + (y/4) - (y/100) + (y/400) - 32045;
        return d;
    }

    mylib::date to_date(int day_number)
    {
        int a = day_number + 32044;
        int b = (4*a + 3)/146097;
        int c = a-((146097*b)/4);
        int d = (4*c + 3)/1461;
        int e = c - (1461*d)/4;
        int m = (5*e + 2)/153;
        int year = 100*b + d - 4800 + (m/10);
        int month = m + 3 - 12 * (m/10);
        int day = e - ((153*m + 2)/5) + 1;
        return mylib::date(year,month,day);
    }
}

mylib::date::date(int year, int month, int day) :
    year(year), month(month), day(day)
{
}

bool mylib::date::is_valid() const
{
    return (month >= 1 && month <= 12) &&
        (day >= 1 && day <= days_in_month(year, month));
}
        
void mylib::date::offset(int offset_in_days)
{
    mylib::date d = to_date(to_day_number(this) + offset_in_days);
    *this = d;
}

int mylib::date::diff(const mylib::date & other) const
{
    return to_day_number(this) - to_day_number(&other);
}

bool mylib::date::is_equal(const mylib::date & other) const
{
    return year == other.year && month == other.month && day == other.day;
}
