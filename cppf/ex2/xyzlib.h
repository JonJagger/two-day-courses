#ifndef XYZLIB_INCLUDED
#define XYZLIB_INCLUDED

static bool xyzlib_is_leap_year(int year)
{
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

static int xyzlib_days_in_month(int year, int month)
{
    switch (month) {
    case 2:
        return xyzlib_is_leap_year(year) ? 29 : 28;
    case 4: case 6: case 9: case 11:
        return 30;
    }
    return 31;
}

static int xyzlib_to_day_number(int year, int month, int day)
{
    int a = (14-month)/12;
    int y = year + 4800 - a;
    int m = month + 12*a - 3;
    int d = day + ((153*m+2)/5) + 365*y + (y/4) - (y/100) + (y/400) - 32045;
    return d;
}

static void xyzlib_to_ymd(int day_number, int * year, int * month, int * day)
{
    int a = day_number + 32044;
    int b = (4*a + 3)/146097;
    int c = a-((146097*b)/4);
    int d = (4*c + 3)/1461;
    int e = c - (1461*d)/4;
    int m = (5*e + 2)/153;
    *year = 100*b + d - 4800 + (m/10);
    *month = m + 3 - 12 * (m/10);
    *day = e - ((153*m + 2)/5) + 1;
}

#endif
