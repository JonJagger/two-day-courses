#include "date.hpp"
#include <cassert>
#include <stdexcept>

int main(void)
{
    // checks valid and invalid dates
    try { mylib::date d(1900,1,1); } catch(std::out_of_range &) { assert(0); }
    try { mylib::date d(2099,12,31); } catch(std::out_of_range &) { assert(0); }
    try { mylib::date d(2000,2,29); } catch(std::out_of_range &) { assert(0); }
    try { mylib::date d(2011,0,13); assert(0); } catch(std::out_of_range &) {}
    try { mylib::date d(2011,9,0); assert(0); } catch(std::out_of_range &) {}
    try { mylib::date d(2011,2,29); assert(0); } catch(std::out_of_range &) {}

    // check date aritmetic
    assert( mylib::date(2011,3,14) - mylib::date(2011,3,13) == 1 );
    assert( mylib::date(2011,3,1) - mylib::date(2011,2,28) == 1 );
    assert( mylib::date(2010,12,31) - mylib::date(2011,1,1) == -1 );
    assert( mylib::date(2011,1,1) - mylib::date(2010,1,1) == 365 );
    assert( mylib::date(2000,3,1) - mylib::date(2000,2,29) == 1 );
    assert( mylib::date(2000,3,1) - mylib::date(2000,2,28) == 2 );
    assert( mylib::date(2001,1,1) - mylib::date(2000,1,1) == 366 );
    assert( mylib::date(2099,12,31) - mylib::date(1900,1,1) == 73048 );
}
