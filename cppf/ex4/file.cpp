#include "file.hpp"
#include "directory_entry_visitor.hpp"

namespace mylib {
    
    file::file(const std::string & name) : name_(name)
    {
    }

    void file::accept(directory_entry_visitor & visitor)
    {
        visitor.visit(*this);
    }

    std::string file::name() const
    {
        return name_;
    }
}
