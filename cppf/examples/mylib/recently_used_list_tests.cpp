#include "recently_used_list.hpp"
#include <cassert>

int main()
{
    mylib::recently_used_list<std::string> rul(4);
    assert(rul.size() == 0);
    rul.push_front("foo");
    rul.push_front("bar");
    rul.push_front("gaz");
    assert(rul.size() == 3);
    assert(rul[0] == "gaz");
    assert(rul[1] == "bar");
    assert(rul[2] == "foo");

    rul.push_front("bar");
    assert(rul.size() == 3);
    assert(rul[0] == "bar");
    assert(rul[1] == "gaz");
    assert(rul[2] == "foo");

    rul.push_front("faz");
    assert(rul.size() == 4);
    assert(rul[0] == "faz");
    assert(rul[1] == "bar");
    assert(rul[2] == "gaz");
    assert(rul[3] == "foo");

    rul.push_front("zzz");
    assert(rul.size() == 4);
    assert(rul[0] == "zzz");
    assert(rul[3] == "gaz");
}
