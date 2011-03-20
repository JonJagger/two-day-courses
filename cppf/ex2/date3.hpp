#ifndef MYLIB_DATE_INCLUDED_
#define MYLIB_DATE_INCLUDED_

namespace mylib {

    class date {
    public:
        date(int year, int month, int day);

        int year() const;
        int month() const;
        int day() const;
        
        date & operator+=(int offset_in_days);
        int operator-(const date & other) const;
        bool operator==(const date & other) const;
    private:
        int year_;
        int month_;
        int day_;
    };

}

#endif
