#include "file.hpp"
#include "directory_entry_visitor.hpp"

mylib::file::file(const std::string & name) : name_(name)
{
}

void mylib::file::accept(directory_entry_visitor * visitor)
{
    visitor->visit(this);
}

std::string mylib::file::name() const
{
    return name_;
}
