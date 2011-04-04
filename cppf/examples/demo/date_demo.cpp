#include "../mylib/date.hpp"
#include <iostream>

namespace mylib
{
    std::ostream & operator<<(std::ostream & out, const date & d)
    {
        return out << d.year() << "/" << d.month() << "/" << d.day();
    }
}

int main()
{
    int year = 2011;
    mylib::date pi_day(year,3,14);
    mylib::date pi_approx_day(year,7,22);
    int days_apart = pi_approx_day - pi_day;

    std::cout
        << "Pi day is " << pi_day << '\n'
        << days_apart << " days later we can celebrate Pi approximation day ("
        << pi_approx_day << ")\n"
        << "(hint, " << pi_approx_day.day() << '/'
        << pi_approx_day.month() << " ~= 3.14)"
        << std::endl;
}
