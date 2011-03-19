#include "date2.hpp"
#include <stdio.h>

static void bubble_sort_dates(mylib::date * base, size_t number_of_elements)
{
    for(;;) {
        bool swapped = false;
        for (size_t i = 0; i < number_of_elements - 1; i++) 
            if (base[i].diff(base[i+1]) > 0) {
                mylib::date tmp = base[i];
                base[i] = base[i+1];
                base[i+1] = tmp;
                swapped = true;
            }
        if (!swapped)
            return;
    }
}

int main(void)
{
    mylib::date dates[] = {mylib::date(1912,6,23), mylib::date(1941,9,9),
                           mylib::date(1943,2,4), mylib::date(1931,10,12),
                           mylib::date(1926,8,27)};
    size_t ndates = sizeof dates / sizeof dates[0];
    bubble_sort_dates(dates, ndates);
    for (size_t i=0; i<ndates; i++)
        printf("%d/%d/%d\n", dates[i].year, dates[i].month, dates[i].day);
}
