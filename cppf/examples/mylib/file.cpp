#include "file.hpp"
#include "directory_entry_visitor.hpp"

namespace mylib {
    
    file::file(const std::string & name) : name_(name), date_(mylib::date(1970,1,1))
    {
    }

    file::~file()
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

    void file::set_date(const mylib::date & d)
    {
        date_ = d;
    }
}
