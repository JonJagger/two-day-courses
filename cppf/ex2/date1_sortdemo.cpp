#include "date1.hpp"
#include <stdio.h>

static void bubble_sort_dates(mylib_date * base, size_t number_of_elements)
{
    for(;;) {
        bool swapped = false;
        for (size_t i = 0; i < number_of_elements - 1; i++) 
            if (mylib_date_diff(&base[i],&base[i+1]) > 0) {
                mylib_date tmp = base[i];
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
    mylib_date dates[] = {{1912,6,23}, {1941,9,9}, {1943,2,4},
                          {1931,10,12}, {1926,8,27}};
    size_t ndates = sizeof dates / sizeof dates[0];
    bubble_sort_dates(dates, ndates);
    for (size_t i=0; i<ndates; i++)
        printf("%d/%d/%d\n", dates[i].year, dates[i].month, dates[i].day);
}
