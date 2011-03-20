#ifndef MYLIB_DATE_INCLUDED_
#define MYLIB_DATE_INCLUDED_

namespace mylib {

    struct date {
        int year;
        int month;
        int day;

        bool is_valid() const;
        void offset(int offset_in_days);
        int diff(const date & other) const;
        bool is_equal(const date & other) const;
    };

}

#endif
