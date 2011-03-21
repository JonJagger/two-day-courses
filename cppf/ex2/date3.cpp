#include "date3.hpp"
#include "xyzlib.h"
#include <stdexcept>

mylib::date::date(int year, int month, int day) :
    year_(year), month_(month), day_(day)
{
    if (!(month >= 1 && month <= 12
          && day >= 1 && day <= xyzlib_days_in_month(year, month)))
        throw std::out_of_range("invalid date");
}

int mylib::date::year() const {
    return year_;
}

int mylib::date::month() const {
    return month_;
}

int mylib::date::day() const {
    return day_;
}

mylib::date & mylib::date::operator+=(int days)
{
    int day_number = xyzlib_to_day_number(year_, month_, day_);
    int new_day_number = day_number + days;
    xyzlib_to_ymd(new_day_number, &year_, &month_, &day_);
    return *this;
}

int mylib::date::operator-(const mylib::date & other) const
{
    int day_number = xyzlib_to_day_number(year_, month_, day_);
    int other_day_number = xyzlib_to_day_number(
        other.year_, other.month_, other.day_);
    return day_number - other_day_number;
}

bool mylib::date::operator==(const mylib::date & other) const
{
    return year_ == other.year_ && month_ == other.month_ && day_ == other.day_;
}
