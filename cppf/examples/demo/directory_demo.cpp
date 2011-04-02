#include "../mylib/directory_entry_visitor.hpp"
#include "../mylib/file.hpp"
#include "../mylib/directory.hpp"
#include <cassert>
#include <iostream>

namespace mylib
{
    std::ostream & operator<<(std::ostream & out, const date & d)
    {
        return out << d.year() << "/" << d.month() << "/" << d.day();
    }
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
    std::cout << prefix << entry.name() << '/'
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
    //mylib::directory root = mylib::directory("root");
    mylib::root_dir root;
    root.create_file("foo");
    root.create_file("bar");
    mylib::directory & gaz = root.create_directory("gaz");
    gaz.create_file("boo");
    gaz.create_file("far");
    mylib::file & gii = root.create_file("gii");
    gii.set_date(mylib::date(2011,3,14));

    my_directory_printer printer(4);
    root.accept(printer);
}
