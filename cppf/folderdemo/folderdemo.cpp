#include "directory.hpp"
#include "file.hpp"
#include "directory_entry_visitor.hpp"
#include "date.hpp"

#include <string>
#include <iostream>

std::ostream & operator<<(std::ostream & out, const mylib::date & date)
{
    return out << date.year() << "/" << date.month() << "/" << date.day();
}

class my_directory_printer : public mylib::directory_entry_visitor
{
public:
    explicit my_directory_printer(int indent_size = 4) : indent_size(indent_size), indent() {}
    void visit(mylib::directory & entry);
    void leave(mylib::directory & entry);
    void visit(mylib::file & entry);
private:
    int indent_size;
    int indent;
};

void my_directory_printer::visit(mylib::directory & entry)
{
    const std::string prefix(indent, ' ');
    std::cout << prefix << entry.name() << "/"
              << " [" << entry.date() << "]" << std::endl;
    indent += indent_size;
}

void my_directory_printer::leave(mylib::directory &)
{
    indent -= indent_size;
}

void my_directory_printer::visit(mylib::file & entry)
{
    const std::string prefix(indent, ' ');
    std::cout << prefix << entry.name()
              << " [" << entry.date() << "]" << std::endl;
}

int main()
{
    mylib::directory root("root", mylib::date(2011,3,29));
    mylib::file foo("foo", mylib::date(2011,2,21));
    mylib::file bar("bar", mylib::date(2007,1,3));
    mylib::directory gaz("gaz", mylib::date(2001,4,5));
    mylib::file boz("boz", mylib::date(1987,12,10));
    mylib::file boo("boo", mylib::date(1998,10,9));
    mylib::file goo("goo", mylib::date(1976,5,6));
    
    root.add(foo);
    root.add(bar);
    root.add(gaz);
    root.add(boz);
    gaz.add(boo);
    gaz.add(goo);

    my_directory_printer printer(4);
    root.accept(printer);
}
