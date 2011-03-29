#include "date3.hpp"
#include "xyzlib.h"
#include <stdexcept>

namespace mylib {
    
    date::date(int year, int month, int day) :
        year_(year), month_(month), day_(day)
    {
        if (!(month_ >= 1 && month_ <= 12
              && day_ >= 1 && day_ <= xyzlib_days_in_month(year_, month_)))
            throw std::out_of_range("invalid date");
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

    int date::operator-(const date & other) const
    {
        int day_number = xyzlib_to_day_number(year_, month_, day_);
        int other_day_number = xyzlib_to_day_number(
            other.year_, other.month_, other.day_);
        return day_number - other_day_number;
    }

    bool date::operator==(const date & other) const
    {
        return year_ == other.year_ && month_ == other.month_ && day_ == other.day_;
    }

}
