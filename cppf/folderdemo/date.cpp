#include "date.hpp"
#include "xyzlib.h"
#include <stdexcept>

namespace {

    void ensure_valid_date(int year, int month, int day) 
    {
        if (!(month >= 1 && month <= 12
              && day >= 1 && day <= xyzlib_days_in_month(year, month)))
            throw std::out_of_range("invalid date");
    }

}

namespace mylib {
    
    date::date(int year, int month, int day) :
        year_(year), month_(month), day_(day)
    {
        ensure_valid_date(year_,month_,day_);
    }

    date::date(const date & other) :
        year_(other.year_), month_(other.month_), day_(other.day_)
    {
        ensure_valid_date(year_,month_,day_);
    }

    int date::year() const
    {
        return year_;
    }

    int date::month() const
    {
        return month_;
    }

    int date::day() const
    {
        return day_;
    }

    date & date::operator+=(int days)
    {
        int day_number = xyzlib_to_day_number(year_, month_, day_);
        int new_day_number = day_number + days;
        xyzlib_to_ymd(new_day_number, &year_, &month_, &day_);
        return *this;
    }

    int date::operator-(const mylib::date & other) const
    {
        int day_number = xyzlib_to_day_number(year_, month_, day_);
        int other_day_number = xyzlib_to_day_number(
            other.year_, other.month_, other.day_);
        return day_number - other_day_number;
    }

    bool date::operator==(const mylib::date & other) const
    {
        return year_ == other.year_ && month_ == other.month_ && day_ == other.day_;
    }

}
