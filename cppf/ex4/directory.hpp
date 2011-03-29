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
        void accept(directory_entry_visitor * visitor);
        std::string name() const;
        void add(directory_entry * entry);
    private:
        typedef std::vector<directory_entry*> container;
        std::string name_;
        container entries_;
    };
    
}

#endif
