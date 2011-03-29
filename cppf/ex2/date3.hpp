#ifndef MYLIB_DATE_HPP_INCLUDED
#define MYLIB_DATE_HPP_INCLUDED

namespace mylib {

    struct date {
    public:
        date(int year, int month, int day);

        int year() const;
        int month() const;
        int day() const;
        
        date & operator+=(int days);
        int operator-(const date & other) const;
        bool operator==(const date & other) const;
    private:
        int year_;
        int month_;
        int day_;
    };

}

#endif
