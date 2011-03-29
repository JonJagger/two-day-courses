#ifndef MYLIB_DATE_HPP_INCLUDED
#define MYLIB_DATE_HPP_INCLUDED

namespace mylib {

    struct date {
        int year;
        int month;
        int day;

        bool is_valid() const;
        void offset(int days);
        int diff(const date & other) const;
        bool is_equal(const date & other) const;
    };

}

#endif
