#include "date2.h"
#include <stdio.h>
#include <stdlib.h>

static void my_printer(const char * message) 
{
    puts(message);
}

int main(void) 
{
    static char global_buffer[size_of_date];
    char local_buffer[size_of_date];
    char * dynamic_buffer = malloc(size_of_date);

    date * d1 = date_init(global_buffer, 2008, 3, 6);
    date * d2 = date_init(local_buffer, 2008, 3, 6);
    date * d3 = date_init(dynamic_buffer, 2008, 3, 7);

    printf("d1 = "); date_print(d1, my_printer);
    printf("d2 = "); date_print(d2, my_printer);
    printf("d3 = "); date_print(d3, my_printer);

    printf("d1 is %sequal to d2\n", date_equal(d1, d2) ? "" : "not ");
    printf("d2 is %sequal to d3\n", date_equal(d2, d3) ? "" : "not ");

    free(dynamic_buffer);

    return 0;
}
