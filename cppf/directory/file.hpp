#ifndef MYLIB_FILE_HPP_INCLUDED
#define MYLIB_FILE_HPP_INCLUDED

#include "directory_entry.hpp"
#include <string>

namespace mylib {
    
    class file : public directory_entry {
    public:
        explicit file(const std::string & name);
        void accept(directory_entry_visitor * visitor);
        std::string name() const;
    private:
        std::string name_;
    };
}

#endif
