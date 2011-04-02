#include "directory.hpp"
#include "directory_entry_visitor.hpp"

namespace mylib {
    
    directory::directory(const std::string & name) : file(name), entries_()
    {
    }

    directory::~directory()
    {
        for (std::vector<directory_entry*>::iterator i = entries_.begin();
             i != entries_.end(); ++i)
            delete (file*)(*i);
    }

    void directory::accept(directory_entry_visitor & visitor)
    {
        visitor.visit(*this);
        for (container::iterator it = entries_.begin();
             it != entries_.end(); ++it) 
            (*it)->accept(visitor);
        visitor.leave(*this);
    }

    mylib::file & directory::create_file(const std::string & name)
    {
        file * f = new file(name);
        entries_.push_back(f);
        return *f;
    }

    mylib::directory & directory::create_directory(const std::string & name)
    {
        directory * d = new directory(name);
        entries_.push_back(d);
        return *d;
    }
}
