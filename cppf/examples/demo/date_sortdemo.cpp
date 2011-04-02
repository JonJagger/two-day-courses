#include "../mylib/date.hpp"
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <sstream>

namespace mylib {

    std::ostream & operator<<(std::ostream & out, const date & d)
    {
        return out << d.year() << "/" << d.month() << "/" << d.day();
    }

    bool operator<(const date & lhs, const date & rhs) {
        return lhs - rhs < 0;
    }

}

template <typename Iterator>
void bubble_sort(Iterator first, Iterator last)
{
    for (Iterator i = first; i != last; ++i)
        for (Iterator j = first; j<i; ++j)
            if (*i < *j)
                std::iter_swap(i,j);
}

int main()
{
    // sort ints
    std::cout << "--- ints" << std::endl;
    int numbers[] = {3,4,2,1,3};
    bubble_sort(numbers, numbers+5);
    std::cout << '[';
    for (int i=0; i<5; i++) 
        std::cout << (i?", ":"") << numbers[i];
    std::cout << ']' << std::endl;

    // sort dates
    std::cout << "--- dates" << std::endl;
    mylib::date dates[] = {mylib::date(1912,6,23), mylib::date(1941,9,9),
                           mylib::date(1943,2,4), mylib::date(1931,10,12),
                           mylib::date(1926,8,27), mylib::date(1912,10,1)};
    size_t ndates = sizeof dates / sizeof dates[0];
    bubble_sort(dates, dates+ndates);
    std::ostream_iterator<mylib::date> out_it(std::cout,"\n");
    std::copy(dates, dates + ndates, out_it);

    // sort strings
    std::cout << "--- strings" << std::endl;
    std::vector<std::string> strings;
    for (mylib::date * it = &dates[0]; it != &dates[ndates]; ++it) {
        std::ostringstream stm;
        stm << *it;
        strings.push_back(stm.str());
    }
    bubble_sort(strings.begin(), strings.end());
    std::copy(strings.begin(), strings.end(),
              std::ostream_iterator<std::string>(std::cout,"\n"));
}
