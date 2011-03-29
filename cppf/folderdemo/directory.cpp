#include "directory.hpp"
#include "directory_entry_visitor.hpp"

namespace {
    const mylib::date default_date(1971,9,13);
}

namespace mylib {
    
    directory::directory(const std::string & name) : name_(name), date_(default_date), entries_()
    {
    }

    directory::directory(const std::string & name, const mylib::date & date) : name_(name), date_(date), entries_()
    {
    }

    void directory::accept(directory_entry_visitor & visitor)
    {
        visitor.visit(*this);
        for (container::iterator it = entries_.begin();
             it != entries_.end(); ++it) 
            (*it)->accept(visitor);
        visitor.leave(*this);
    }

    std::string directory::name() const
    {
        return name_;
    }

    mylib::date directory::date() const
    {
        return date_;
    }

    void directory::add(directory_entry & entry)
    {
        entries_.push_back(&entry);
    }

}
