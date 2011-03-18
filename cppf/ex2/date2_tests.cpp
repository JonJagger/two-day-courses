#include "date2.hpp"
#include <cassert>
#include <cstring>

static void bubble_sort_dates(mylib::date * base, size_t number_of_elements)
{
    for(;;) {
        bool swapped = false;
        for (size_t i = 0; i < number_of_elements - 1; i++) 
            if (base[i].diff(base[i+1]) > 0) {
                mylib::date tmp = base[i];
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
        assert( mylib::date(1971,9,13).is_valid() );
        assert( mylib::date(1900,1,1).is_valid() );
        assert( mylib::date(2099,12,31).is_valid() );
        assert( mylib::date(2000,2,29).is_valid() );
        assert( !mylib::date(0,9,13).is_valid() );
        assert( !mylib::date(1971,0,13).is_valid() );
        assert( !mylib::date(1971,9,0).is_valid() );
        assert( !mylib::date(1971,13,9).is_valid() );
        assert( !mylib::date(1971,9,31).is_valid() );
        assert( !mylib::date(2100,1,1).is_valid() );
        assert( !mylib::date(1899,12,31).is_valid() );
    }

    // check offsets around a leap year day
    {
        mylib::date d1(2000,2,29);
        mylib::date d2(2000,3,1);
        assert( d2.diff(d1) == 1 );
        assert( !d2.is_equal(d1) );
        d1.offset(1);
        assert( d2.diff(d1) == 0 );
        assert( d2.is_equal(d1) );
        d1.offset(-10);
        d2.offset(10);
        assert( !d1.is_equal(d2) );
        assert( d2.diff(d1) == 20 );
    }

    // check boundaries and check that all dates in between are valid
    {
        mylib::date d1(1900,1,1);
        mylib::date d2(2099,12,31);
        assert( d2.diff(d1) == 73048 );
        assert( d1.diff(d2) == -73048 );
        for (mylib::date d(d1); !d.is_equal(d2); d.offset(1))
            assert(d.is_valid());
        for (mylib::date d(d2); !d.is_equal(d1); d.offset(-1))
            assert(d.is_valid());
    }

    // check that offset does not create invalid dates
    {
        mylib::date d1(1900,1,1);
        mylib::date d2(2099,12,31);
        d1.offset(-1);
        assert(d1.is_valid());
        d2.offset(1);
        assert(d2.is_valid());
    }

    // check that we are able to bubble sort an array of dates
    {
        mylib::date dates[] = {mylib::date(2002,3,13), mylib::date(2005,4,20), mylib::date(1971,9,13), mylib::date(1970,5,1)};
        bubble_sort_dates(dates, 4);
        assert( dates[0].is_equal(mylib::date(1970,5,1)) );
        assert( dates[1].is_equal(mylib::date(1971,9,13)) );
        assert( dates[2].is_equal(mylib::date(2002,3,13)) );
        assert( dates[3].is_equal(mylib::date(2005,4,20)) );
    }

}
