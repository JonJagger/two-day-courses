/* usedate2.c */

#include "date2.h"

#include <stdio.h>
#include <stdlib.h>

void my_printer(const char * message) 
{
    puts(message);
}

static char d1_buffer[size_of_date];

int main(void) 
{
    char d2_buffer[size_of_date];
    char * d3_buffer = malloc(size_of_date);

    struct date * d1 = date_init(d1_buffer, 2008, 3, 6);
    struct date * d2 = date_init(d2_buffer, 2008, 3, 6);
    struct date * d3 = date_init(d3_buffer, 2008, 3, 7);

    printf("d1 = "); date_print(d1, my_printer);
    printf("d2 = "); date_print(d2, my_printer);
    printf("d3 = "); date_print(d3, my_printer);

    printf("d1 is %s to d2\n", date_equal(d1, d2) ? "equal" : "not equal");
    printf("d2 is %s to d3\n", date_equal(d2, d3) ? "equal" : "not equal");

    free(d3_buffer);
}
