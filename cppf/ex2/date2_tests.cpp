#include "date2.hpp"
#include <cassert>

int main(void)
{
    // checks valid and invalid dates
    {
        assert( mylib::date(1971,9,13).is_valid() );
        assert( mylib::date(1900,1,1).is_valid() );
        assert( mylib::date(2099,12,31).is_valid() );
        assert( mylib::date(2000,2,29).is_valid() );
        assert( !mylib::date(1971,0,13).is_valid() );
        assert( !mylib::date(1971,9,0).is_valid() );
        assert( !mylib::date(1971,13,9).is_valid() );
        assert( !mylib::date(1971,9,31).is_valid() );
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

    // check that all dates between 1900/1/1 and 2099/12/31 are valid
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

}
