#include "recently_used_list.hpp"
#include <cassert>
#include <iostream>
#include <sstream>
#include <cassert>

#define TEST_EQUAL(expr1,expr2)                                         \
    do {                                                                \
        std::stringstream s1, s2;                                       \
        s1 << std::boolalpha << (expr1);                                \
        s2 << std::boolalpha << (expr2);                                \
        std::cerr << "TEST_EQUAL(#expr1,#expr2) --> ";                  \
        if (s1.str() == s2.str())                                       \
            std::cerr << "OK!" << std::endl;                            \
        else                                                            \
            std::cerr << "FAILED "                                      \
                      << "(expected " << s2.str()                       \
                      << " got " << s1.str() << ")" << std::endl;       \
    } while(0)                                                          \

std::ostream & operator<<(std::ostream & os, const mylib::recently_used_list & list)
{
    int count = 0;
    os << "[";
    for (mylib::recently_used_list::const_iterator it = list.begin();
         it != list.end(); ++it)
        os << (count++==0?"":",") << (*it);
    os << "]";
}

int main()
{
    mylib::recently_used_list rul(4);
    std::cout << rul << std::endl;

    TEST_EQUAL(rul.size(), 0);

    rul.push_back("foo");
    TEST_EQUAL(rul.size(), 1);
    TEST_EQUAL(*rul.begin(), "foo");

    rul.push_back("bar");
    std::cout << rul << std::endl;
    TEST_EQUAL(rul.size(), 2);
    TEST_EQUAL(*rul.begin(), "bar");

    rul.push_back("bar");
    std::cout << rul << std::endl;
    TEST_EQUAL(rul.size(), 2);
    TEST_EQUAL(*rul.begin(), "bar");

    rul.push_back("foo");
    std::cout << rul << std::endl;
    TEST_EQUAL(rul.size(), 2);
    TEST_EQUAL(*rul.begin(), "foo");
    TEST_EQUAL(*(rul.begin()+1), "bar");

    rul.push_back("foz");
    std::cout << rul << std::endl;
    TEST_EQUAL(rul.size(), 3);

    rul.push_back("boz");
    std::cout << rul << std::endl;
    TEST_EQUAL(rul.size(), 4);

    rul.push_back("gaz");
    std::cout << rul << std::endl;
    TEST_EQUAL(rul.size(), 4);

    mylib::recently_used_list rul2(rul);
    std::cout << rul2 << std::endl;
    TEST_EQUAL(rul2.size(), 4);

    mylib::recently_used_list rul3;
    TEST_EQUAL(rul3.empty(), true);
    rul3 = rul2;
    TEST_EQUAL(rul3.empty(), false);
    std::cout << rul3 << std::endl;
    TEST_EQUAL(rul3.size(), 4);
}

    
