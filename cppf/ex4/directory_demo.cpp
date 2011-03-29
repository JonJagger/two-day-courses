#include "directory.hpp"
#include "file.hpp"
#include "directory_entry_visitor.hpp"
#include <string>
#include <iostream>

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
    std::cout << prefix << entry.name() << "/" << std::endl;
    indent += indent_size;
}

void my_directory_printer::leave(mylib::directory &)
{
    indent -= indent_size;
}

void my_directory_printer::visit(mylib::file & entry)
{
    const std::string prefix(indent, ' ');
    std::cout << prefix << entry.name() << std::endl;
}

int main()
{
    mylib::directory root("root");
    mylib::file foo("foo");
    mylib::file bar("bar");
    mylib::directory gaz("gaz");
    mylib::file boz("boz");
    mylib::file boo("boo");
    mylib::file goo("goo");
    
    root.add(foo);
    root.add(bar);
    root.add(gaz);
    root.add(boz);
    gaz.add(boo);
    gaz.add(goo);

    my_directory_printer printer(4);
    root.accept(printer);
}
