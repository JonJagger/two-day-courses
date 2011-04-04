#ifndef MYLIB_RECENTLY_USED_LIST_HPP_INCLUDED
#define MYLIB_RECENTLY_USED_LIST_HPP_INCLUDED

#include <vector>
#include <string>
#include <stdexcept>
#include <stdlib.h>

namespace mylib {

    template <typename T>
    class recently_used_list
    {
    public:
        explicit recently_used_list(size_t);
        size_t size() const;
        void push_front(T const &);
        T const & operator[](size_t) const;
    private:
        std::vector<T> elements;
        size_t max_size;
    };

    template <typename T>
    recently_used_list<T>::recently_used_list(size_t s)
        : elements(), max_size(s)
    {
    }

    template <typename T>
    size_t recently_used_list<T>::size() const
    {
        return elements.size();
    }

    template <typename T>
    void recently_used_list<T>::push_front(T const & e)
    {
        typename std::vector<T>::iterator it;
        it = find(elements.begin(), elements.end(), e);
        if (it != elements.end())
            elements.erase(it);
        if (elements.size() == max_size)
            elements.pop_back();
        elements.insert(elements.begin(), e);
    }

    template <typename T>
    T const & recently_used_list<T>::operator[](size_t index) const
    {
        return elements.at(index);
    }

}

#endif 
