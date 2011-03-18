#include "date3.hpp"
#include <cassert>
#include <cstring>
#include <stdexcept>

bool operator<(const mylib::date & lhs, const mylib::date & rhs) {
    return lhs - rhs < 0;
}

template <typename T>
static void bubble_sort_dates(T * base, size_t number_of_elements)
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
    // checks valid and invalid dates
    {
        try { mylib::date d(1971,9,13); } catch(std::out_of_range &) { assert(0); }
        try { mylib::date d(1900,1,1); } catch(std::out_of_range &) { assert(0); }
        try { mylib::date d(2099,12,31); } catch(std::out_of_range &) { assert(0); }
        try { mylib::date d(2000,2,29); } catch(std::out_of_range &) { assert(0); }

        try { mylib::date d(0,9,13); assert(0); } catch(std::out_of_range &) {}
        try { mylib::date d(1971,0,13); assert(0); } catch(std::out_of_range &) {}
        try { mylib::date d(1971,9,0); assert(0); } catch(std::out_of_range &) {}
        try { mylib::date d(1971,13,9); assert(0); } catch(std::out_of_range &) {}
        try { mylib::date d(1971,9,31); assert(0); } catch(std::out_of_range &) {}
        try { mylib::date d(2100,1,1); assert(0); } catch(std::out_of_range &) {}
        try { mylib::date d(1899,12,31); assert(0); } catch(std::out_of_range &) {}
    }

    // check offsets around a leap year day
    {
        mylib::date d1(2000,2,29);
        mylib::date d2(2000,3,1);
        assert( d2 - d1 == 1 );
        assert( d2 != d1 );
        d1 += 1;
        assert( d2 == d1 );
        d1 -= 10;
        d2 += 10;
        assert( d1 != d2 );
        assert( d2 - d1 == 20 );
    }

    // check boundaries and we assume that all dates in between are valid
    {
        mylib::date d1(1900,1,1);
        mylib::date d2(2099,12,31);
        assert( d2 - d1 == 73048 );
        assert( d1 - d2 == -73048 );
    }

    // check that moving out of valid range creates exception
    {
        mylib::date d1(1900,1,1);
        mylib::date d2(2099,12,31);
        try { d1 -= 1; assert(0); } catch(std::out_of_range &) {}
        try { d2 += 1; assert(0); } catch(std::out_of_range &) {}
    }

    // check that we are able to bubble sort an array of dates
    {
        mylib::date dates[] = {mylib::date(2002,3,13), mylib::date(2005,4,20), mylib::date(1971,9,13), mylib::date(1970,5,1)};
        bubble_sort_dates(dates, 4);
        assert( dates[0] == mylib::date(1970,5,1) );
        assert( dates[1] == mylib::date(1971,9,13) );
        assert( dates[2] == mylib::date(2002,3,13) );
        assert( dates[3] == mylib::date(2005,4,20) );
    }


}
