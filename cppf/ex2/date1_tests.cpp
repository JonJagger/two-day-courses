#include "date1.hpp"
#include <assert.h>

static mylib_date * to_date(int year, int month, int day) {
    mylib_date d2 = {year,month,day};
    static mylib_date d;
    d = d2;
    return &d;
}

int main(void)
{
    // checks valid and invalid dates
    {
        assert( mylib_date_is_valid(to_date(1971,9,13)) );
        assert( mylib_date_is_valid(to_date(1900,1,1)) );
        assert( mylib_date_is_valid(to_date(2099,12,31)) );
        assert( mylib_date_is_valid(to_date(2000,2,29)) );
        assert( !mylib_date_is_valid(to_date(1971,0,13)) );
        assert( !mylib_date_is_valid(to_date(1971,9,0)) );
        assert( !mylib_date_is_valid(to_date(1971,13,9)) );
        assert( !mylib_date_is_valid(to_date(1971,9,31)) );
    }

    // check offsets around a leap year day
    {
        mylib_date d1 = {2000,2,29};
        mylib_date d2 = {2000,3,1};
        assert( mylib_date_diff(&d2,&d1) == 1 );
        assert( !mylib_date_is_equal(&d1,&d2) );
        mylib_date_offset(&d1,1);
        assert( mylib_date_diff(&d2,&d1) == 0 );
        assert( mylib_date_is_equal(&d1,&d2) );
        mylib_date_offset(&d1,-10);
        mylib_date_offset(&d2,10);
        assert( !mylib_date_is_equal(&d1,&d2) );
        assert( mylib_date_diff(&d2,&d1) == 20 );
    }

    // check that all dates between 1900/1/1 and 2099/12/31 are valid
    {
        mylib_date d1 = {1900,1,1};
        mylib_date d2 = {2099,12,31};
        assert( mylib_date_diff(&d2,&d1) == 73048 );
        assert( mylib_date_diff(&d1,&d2) == -73048 );
        for (mylib_date d = d1; !mylib_date_is_equal(&d,&d2); mylib_date_offset(&d,1))
            assert(mylib_date_is_valid(&d));
        for (mylib_date d = d2; !mylib_date_is_equal(&d,&d1); mylib_date_offset(&d,-1))
            assert(mylib_date_is_valid(&d));
    }
}
