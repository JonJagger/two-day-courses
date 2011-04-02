#ifndef MYLIB_DIRECTORY_HPP_INCLUDED
#define MYLIB_DIRECTORY_HPP_INCLUDED

#include "file.hpp"

#include <vector>

namespace mylib {
    
    class directory : public file
    {
    public:
        explicit directory(const std::string & name);
        ~directory();
        void accept(directory_entry_visitor & visitor);
        file & create_file(const std::string & name);
        directory & create_directory(const std::string & name);
        friend directory create_root(const std::string & name);
    private:
        typedef std::vector<directory_entry*> container;
        container entries_;
    };

    class root_dir : public directory
    {
    public:
        root_dir() : directory("(root)") {}
        ~root_dir() {}
    };

}

#endif
