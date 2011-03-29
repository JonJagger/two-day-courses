#include "directory.hpp"
#include "directory_entry_visitor.hpp"

namespace mylib {
    
    directory::directory(const std::string & name) : name_(name), entries_()
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

    void directory::add(directory_entry & entry)
    {
        entries_.push_back(&entry);
    }

}
