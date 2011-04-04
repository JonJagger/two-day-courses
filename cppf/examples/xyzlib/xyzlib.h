#ifndef XYZLIB_INCLUDED
#define XYZLIB_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

bool xyzlib_is_leap_year(int year);
int xyzlib_days_in_month(int year, int month);
int xyzlib_to_day_number(int year, int month, int day);
void xyzlib_to_ymd(int day_number, int * year, int * month, int * day);

#ifdef __cplusplus
} 
#endif

#endif
