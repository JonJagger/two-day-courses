#ifndef MYLIB_FILE_HPP_INCLUDED
#define MYLIB_FILE_HPP_INCLUDED

#include "directory_entry.hpp"
#include "date.hpp"
#include <string>

namespace mylib {
    
    class file : public directory_entry {
    public:
        explicit file(const std::string & name);
        ~file();
        void accept(directory_entry_visitor & visitor);
        std::string name() const;
        mylib::date date() const;
        void set_date(const mylib::date & d);
    private:
        std::string name_;
        mylib::date date_;
    };
}

#endif
