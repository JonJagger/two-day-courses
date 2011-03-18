#ifndef MYLIB_DATE_INCLUDED_
#define MYLIB_DATE_INCLUDED_

#include <stdbool.h>

typedef struct mylib_date {
    int year;
    int month;
    int day;
} mylib_date;

bool mylib_date_is_valid(const mylib_date * date);
void mylib_date_offset(mylib_date * date, int offset_in_days);
int mylib_date_diff(const mylib_date * date1, const mylib_date * date2);
bool mylib_date_is_equal(const mylib_date * date1, const mylib_date * date2);

#endif
