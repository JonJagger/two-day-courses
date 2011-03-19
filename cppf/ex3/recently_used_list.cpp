#include "recently_used_list.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <ostream>

using namespace mylib;

recently_used_list::recently_used_list()
    : max_size_(0)
    , items_()
{
}

recently_used_list::recently_used_list(size_type max_size)
    : max_size_(max_size)
    , items_()
{
}

recently_used_list::recently_used_list(const recently_used_list & other)
    : max_size_(other.max_size_)
    , items_(other.items_)
{
}

recently_used_list & recently_used_list::operator=(
    const mylib::recently_used_list & other)
{
    max_size_ = other.max_size_;
    items_.clear();
    items_.assign(other.begin(),other.end());
}

recently_used_list::const_iterator recently_used_list::begin() const
{
    return items_.begin();
}

recently_used_list::const_iterator recently_used_list::end() const
{
    return items_.end();
}
    
recently_used_list::size_type recently_used_list::max_size() const
{
    return max_size_;
}

recently_used_list::size_type recently_used_list::size() const
{
    return items_.size();
}

bool recently_used_list::empty() const
{
    return items_.empty();
}

void recently_used_list::push_back(std::string item)
{
    iterator it = find(items_.begin(),items_.end(),item);
    if (it != items_.end())
        items_.erase(it);
    if (max_size_ != 0 && items_.size() == max_size_) 
        items_.pop_back();
    items_.insert(items_.begin(),item);
}
