#include "date.hpp"
#include "file.hpp"
#include "directory_entry_visitor.hpp"

namespace {
    const mylib::date default_date(1971,9,13);
}

namespace mylib {
    
    file::file(const std::string & name) : name_(name), date_(default_date)
    {
    }

    file::file(const std::string & name, const mylib::date & d) : name_(name), date_(d)
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

    mylib::date file::date() const
    {
        return date_;
    }

}
