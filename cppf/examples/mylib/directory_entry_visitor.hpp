#ifndef MYLIB_DIRECTORY_ENTRY_VISITOR_HPP_INCLUDED
#define MYLIB_DIRECTORY_ENTRY_VISITOR_HPP_INCLUDED

namespace mylib {
    
    class directory;
    class file;

    class directory_entry_visitor {
    public:
        virtual void visit(directory &) = 0;
        virtual void leave(directory &) = 0;
        virtual void visit(file &) = 0;
    protected:
        virtual ~directory_entry_visitor() {}
    };

}

#endif
