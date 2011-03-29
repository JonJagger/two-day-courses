#ifndef MYLIB_RECENTLY_USED_LIST_HPP_INCLUDED
#define MYLIB_RECENTLY_USED_LIST_HPP_INCLUDED

#include <vector>
#include <iterator>

namespace mylib {

    class recently_used_list {
    public:
        typedef std::vector<std::string> container;
        typedef container::size_type size_type;
        typedef container::iterator iterator;
        typedef container::const_iterator const_iterator;

        recently_used_list();
        explicit recently_used_list(size_type max_size);
        explicit recently_used_list(const recently_used_list & other);
        recently_used_list & operator=(const recently_used_list & other);

        const_iterator begin() const;
        const_iterator end() const;
        size_type max_size() const;
        size_type size() const;
        bool empty() const;

        void push_back(std::string item);
    private:
        size_type max_size_;
        container items_;
    };
}

#endif
