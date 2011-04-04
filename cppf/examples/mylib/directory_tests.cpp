#include "directory.hpp"
#include <cassert>

int main()
{
    //mylib::directory root = mylib::directory("root");
    mylib::root_dir root = mylib::root_dir();
    assert(root.name() == "(root)");
    assert(root.date() == mylib::date(1970,1,1));
    root.create_file("foo");
    root.create_file("bar");
    mylib::directory & gaz = root.create_directory("gaz");
    gaz.create_file("boo");
    gaz.create_file("far");
    mylib::file & gii = root.create_file("gii");
    gii.set_date(mylib::date(2011,3,14));
    assert(gii.date() == mylib::date(2011,3,14));
}
