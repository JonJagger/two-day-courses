#include "date2.hpp"
#include "xyzlib.h"

namespace mylib {
    
    bool date::is_valid() const
    {
        return this->month >= 1 && this->month <= 12
            && this->day >= 1
            && this->day <= xyzlib_days_in_month(this->year, this->month);
    }
        
    void date::offset(int days)
    {
        int day_number = xyzlib_to_day_number(this->year, this->month, this->day);
        int new_day_number = day_number + days;
        xyzlib_to_ymd(new_day_number, &this->year, &this->month, &this->day);
    }

    int date::diff(const mylib::date & other) const
    {
        int day_number = xyzlib_to_day_number(this->year, this->month, this->day);
        int other_day_number = xyzlib_to_day_number(
            other.year, other.month, other.day);
        return day_number - other_day_number;
    }

    bool date::is_equal(const mylib::date & other) const
    {
        return this->year == other.year &&
            this->month == other.month &&
            this->day == other.day;
    }

}
