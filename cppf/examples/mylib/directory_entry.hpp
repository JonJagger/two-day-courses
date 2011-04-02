#ifndef MYLIB_DIRECTORY_ENTRY_HPP_INCLUDED
#define MYLIB_DIRECTORY_ENTRY_HPP_INCLUDED

#include <string>
#include "date.hpp"

namespace mylib {
    
    class directory_entry_visitor;

    class directory_entry {
    public:
        virtual void accept(directory_entry_visitor &) = 0;
        virtual std::string name() const = 0;
        virtual mylib::date date() const = 0;
        virtual ~directory_entry() {}
    };
    
}

#endif
