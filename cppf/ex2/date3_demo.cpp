#include "date3.hpp"
#include <iostream>

namespace mylib {
    std::ostream & operator<<(std::ostream & out, const date & date)
    {
        return out << date.year() << "/" << date.month() << "/" << date.day();
    }

    date operator-(date date, int offset_in_days) {
        return date += -offset_in_days;
    }
}

int main()
{
    mylib::date pi_day(2011,3,14);
    mylib::date pi_approx_day(2011,7,22);
    int days_apart = pi_approx_day - pi_day;
    mylib::date just_another_day = pi_day - 42;
    bool is_same = just_another_day == mylib::date(2011,1,31);

    std::cout
        << "Pi day is " << pi_day << '\n'
        << "Pi approximation day is " << pi_approx_day 
        << " (hint, " << pi_approx_day.day() << '/'
        << pi_approx_day.month() << " ~= Pi)\n"
        << "Pi day and Pi approximation day are always " << days_apart
        << " days apart\n"
        << just_another_day << " is 42 days before Pi day, which is"
        << (is_same?" ":" not ") << "the last day of january" << std::endl;
}
