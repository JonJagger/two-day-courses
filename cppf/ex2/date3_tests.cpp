#include "date3.hpp"
#include <cassert>
#include <stdexcept>

int main(void)
{
    // checks valid and invalid dates
    {
        try { mylib::date d(1971,9,13); } catch(std::out_of_range &) { assert(0); }
        try { mylib::date d(1900,1,1); } catch(std::out_of_range &) { assert(0); }
        try { mylib::date d(2099,12,31); } catch(std::out_of_range &) { assert(0); }
        try { mylib::date d(2000,2,29); } catch(std::out_of_range &) { assert(0); }

        try { mylib::date d(1971,0,13); assert(0); } catch(std::out_of_range &) {}
        try { mylib::date d(1971,9,0); assert(0); } catch(std::out_of_range &) {}
        try { mylib::date d(1971,13,9); assert(0); } catch(std::out_of_range &) {}
        try { mylib::date d(1971,9,31); assert(0); } catch(std::out_of_range &) {}
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

    // check that days between 1900/1/1 and 2099/12/31 are correct
    {
        mylib::date d1(1900,1,1);
        mylib::date d2(2099,12,31);
        assert( d2 - d1 == 73048 );
        assert( d1 - d2 == -73048 );
    }
}
