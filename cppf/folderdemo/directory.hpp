#ifndef MYLIB_DIRECTORY_HPP_INCLUDED
#define MYLIB_DIRECTORY_HPP_INCLUDED

#include "directory_entry.hpp"
#include <vector>
#include <string>

namespace mylib {
    
    class directory_entry_visitor;

    class directory : public directory_entry
    {
    public:
        explicit directory(const std::string & name);
        directory(const std::string & name, const mylib::date & date);
        void accept(directory_entry_visitor & visitor);
        std::string name() const;
        mylib::date date() const;
        void add(directory_entry & entry);
    private:
        typedef std::vector<directory_entry*> container;
        std::string name_;
        mylib::date date_;
        container entries_;
    };
    
}

#endif
