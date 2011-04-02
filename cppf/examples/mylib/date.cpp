#include "date.hpp"
#include "../xyzlib/xyzlib.h"
#include <stdexcept>

namespace mylib {
    
    inline int to_day_number(const date & d)
    {
        return xyzlib_to_day_number(d.year(), d.month(), d.day());
    }
        
    date::date(int year, int month, int day)
        : year_(year), month_(month), day_(day)
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

    int date::operator-(const date & other) const
    {
        return to_day_number(*this) - to_day_number(other);
    }

}

bool mylib::operator==(const date & lhs, const date & rhs)
{
    return lhs.year() == rhs.year() &&
        lhs.month() == rhs.month() &&
        lhs.day() == rhs.day();
}
