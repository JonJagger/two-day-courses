#ifndef MYLIB_DATE_INCLUDED
#define MYLIB_DATE_INCLUDED

struct mylib_date {
    int year;
    int month;
    int day;
};

bool mylib_date_is_valid(const mylib_date * date);
void mylib_date_offset(mylib_date * date, int days);
int mylib_date_diff(const mylib_date * date, const mylib_date * other_date);
bool mylib_date_is_equal(const mylib_date * date, const mylib_date * other_date);

#endif
