/* usedate.c */

#include "date.h"
#include <stdio.h>

void my_printer(const char * message) 
{
    puts(message);
}

int main(void) 
{
    struct date * d1 = date_create(2008, 3, 6);
    struct date * d2 = date_create(2008, 3, 6);
    struct date * d3 = date_create(2008, 3, 7);

    printf("d1 = "); date_print(d1, my_printer);
    printf("d2 = "); date_print(d2, my_printer);
    printf("d3 = "); date_print(d3, my_printer);

    printf("d1 is %s to d2\n", date_equal(d1, d2) ? "equal" : "not equal");
    printf("d2 is %s to d3\n", date_equal(d2, d3) ? "equal" : "not equal");

    date_destroy(d3);
    date_destroy(d2);
    date_destroy(d1);
}
