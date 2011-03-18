#include "date1.hpp"
#include <assert.h>
#include <string.h>

static mylib_date * to_date(int year, int month, int day) {
    mylib_date d2 = {year,month,day};
    static mylib_date d;
    d = d2;
    return &d;
}

static void bubble_sort_dates(mylib_date * base, size_t number_of_elements)
{
    for(;;) {
        bool swapped = false;
        for (size_t i = 0; i < number_of_elements - 1; i++) 
            if (mylib_date_diff(&base[i],&base[i+1]) > 0) {
                mylib_date tmp = base[i];
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
        assert( mylib_date_is_valid(to_date(1971,9,13)) );
        assert( mylib_date_is_valid(to_date(1900,1,1)) );
        assert( mylib_date_is_valid(to_date(2099,12,31)) );
        assert( mylib_date_is_valid(to_date(2000,2,29)) );
        assert( !mylib_date_is_valid(to_date(0,9,13)) );
        assert( !mylib_date_is_valid(to_date(1971,0,13)) );
        assert( !mylib_date_is_valid(to_date(1971,9,0)) );
        assert( !mylib_date_is_valid(to_date(1971,13,9)) );
        assert( !mylib_date_is_valid(to_date(1971,9,31)) );
        assert( !mylib_date_is_valid(to_date(2100,1,1)) );
        assert( !mylib_date_is_valid(to_date(1899,12,31)) );
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

    // check boundaries and check that all dates in between are valid
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

    // check that moving outside of valid range really invalidates the date
    {
        mylib_date d1 = {1900,1,1};
        mylib_date d2 = {2099,12,31};
        mylib_date_offset(&d1,-1); 
        assert(!mylib_date_is_valid(&d1));
        mylib_date_offset(&d2,1); 
        assert(!mylib_date_is_valid(&d2));

        mylib_date_offset(&d1,1); 
        assert(!mylib_date_is_valid(&d1));
        mylib_date_offset(&d2,-1); 
        assert(!mylib_date_is_valid(&d2));
    }

    // check that we are able to bubble sort an array of dates
    {
        mylib_date dates[] = {{2002,3,13}, {2005,4,20}, {1971,9,13}, {1970,5,1}};
        bubble_sort_dates(dates, 4);
        assert( mylib_date_is_equal(&dates[0],to_date(1970,5,1)) );
        assert( mylib_date_is_equal(&dates[1],to_date(1971,9,13)) );
        assert( mylib_date_is_equal(&dates[2],to_date(2002,3,13)) );
        assert( mylib_date_is_equal(&dates[3],to_date(2005,4,20)) );
    }

}
