#include "directory.hpp"
#include "directory_entry_visitor.hpp"

mylib::directory::directory(const std::string & name) : name_(name), entries_()
{
}

void mylib::directory::accept(directory_entry_visitor * visitor)
{
    visitor->visit(this);
    for (container::iterator it = entries_.begin();
         it != entries_.end(); ++it) 
        (*it)->accept(visitor);
    visitor->leave(this);
}

std::string mylib::directory::name() const
{
    return name_;
}

void mylib::directory::add(directory_entry * entry)
{
    entries_.push_back(entry);
}
