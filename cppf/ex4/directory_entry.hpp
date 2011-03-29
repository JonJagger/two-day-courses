#ifndef MYLIB_DIRECTORY_ENTRY_HPP_INCLUDED
#define MYLIB_DIRECTORY_ENTRY_HPP_INCLUDED

#include <string>

namespace mylib {
    
    class directory_entry_visitor;

    class directory_entry {
    public:
        virtual void accept(directory_entry_visitor &) = 0;

        virtual std::string name() const = 0;
    protected:
        ~directory_entry() {}
    };
    
}

#endif
