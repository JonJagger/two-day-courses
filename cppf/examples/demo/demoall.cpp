#include "../mylib/date.hpp"
#include "../mylib/recently_used_list.hpp"
#include "../mylib/directory.hpp"
#include "../mylib/file.hpp"                             
#include <cassert>
#include <iostream>

namespace mylib {
    std::ostream & operator<<(std::ostream & out, const date & d)
    {
        return out << d.year() << "/" << d.month() << "/" << d.day();
    }
    
    std::ostream & operator<<(std::ostream & out, mylib::directory_entry * e)
    {
        return out << e->name() << " [" << e->date() << ']';
    }

    std::ostream & operator<<(std::ostream & out, mylib::recently_used_list<mylib::directory_entry*> & e)
    {
        for (size_t i=0; i<e.size(); i++) 
            out << '[' << i << "] " << e[i] << '\n';
        return out << std::flush;
    }
}

int main()
{
    mylib::file foo("foo");
    mylib::file bar("bar");
    mylib::file gaz("gaz");
    mylib::file too("too");
    mylib::file raz("raz");

    mylib::recently_used_list<mylib::directory_entry*> rul(3);
    rul.push_front(&foo);
    std::cout << rul;
    rul.push_front(&bar);
    rul.push_front(&gaz);
    assert(rul.size() == 3);
    std::cout << rul;
    rul.push_front(&bar);
    std::cout << rul;
}
