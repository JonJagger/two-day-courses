#include "date3.hpp"
#include <iostream>
#include <iterator>

namespace mylib {

    std::ostream & operator<<(std::ostream & out, const date & date)
    {
        return out << date.year() << "/" << date.month() << "/" << date.day();
    }

    bool operator<(const date & lhs, const date & rhs) {
        return lhs - rhs < 0;
    }

}

template <typename T>
void bubble_sort(T * base, size_t number_of_elements)
{
    for(;;) {
        bool swapped = false;
        for (size_t i = 0; i < number_of_elements - 1; i++) 
            if (! (base[i] < base[i+1]) ) {
                T tmp = base[i];
                base[i] = base[i+1];
                base[i+1] = tmp;
                swapped = true;
            }
        if (!swapped)
            return;
    }
}

int main(void)
{
    mylib::date dates[] = {mylib::date(1912,6,23), mylib::date(1941,9,9),
                           mylib::date(1943,2,4), mylib::date(1931,10,12),
                           mylib::date(1926,8,27)};
    size_t ndates = sizeof dates / sizeof dates[0];
    bubble_sort(dates, ndates);
    std::ostream_iterator<mylib::date> out_it(std::cout,"\n");
    std::copy(dates, dates + ndates, out_it);
}
