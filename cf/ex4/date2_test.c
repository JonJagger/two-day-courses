#include "date2.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

static void require_that_valid_dates_can_be_initialized(void) 
{
    char buffer[size_of_date];
    assert(date_init(&buffer, 2008, 2, 29) != NULL);
    assert(date_init(&buffer, 2008, 3, 6) != NULL);
    assert(date_init(&buffer, 0, 1, 1) != NULL);
    assert(date_init(&buffer, 9999, 12, 31) != NULL);
}

static void require_that_invalid_date_cannot_be_initialized(void) 
{
    char buffer[size_of_date];
    assert(date_init(&buffer, 10000, 3, 6) == NULL);
    assert(date_init(&buffer, -1, 3, 6) == NULL);
    assert(date_init(&buffer, 2008, 13, 6) == NULL);
    assert(date_init(&buffer, 2008, 0, 6) == NULL);
    assert(date_init(&buffer, 2008, 3, 32) == NULL);
    assert(date_init(&buffer, 2008, 3, 0) == NULL);
    assert(date_init(&buffer, 2008, 2, 30) == NULL);
    assert(date_init(&buffer, 2007, 2, 29) == NULL);
}

static void require_that_dates_values_can_be_compared(void) 
{
    char buffer1[size_of_date];
    char buffer2[size_of_date];
    char buffer3[size_of_date];
    
    date * d1 = date_init(&buffer1, 2008, 3, 6);
    date * d2 = date_init(&buffer2, 2008, 3, 6);
    date * d3 = date_init(&buffer3, 2008, 3, 7);
    
    assert(date_equal(d1, d1));
    assert(date_equal(d1, d2));
    assert(!date_equal(d1, d3));
}

static char my_printer_buffer[1024];

static void my_printer(const char * message) 
{
    strncpy(my_printer_buffer, message, sizeof(my_printer_buffer));
    my_printer_buffer[sizeof(my_printer_buffer) - 1] = '\0';
}

static void require_that_dates_can_be_printed(void) 
{
    char buffer[size_of_date];

    date_print(date_init(&buffer, 2008, 3, 6), my_printer);
    assert(strcmp(my_printer_buffer, "2008-03-06") == 0);

    date_print(date_init(&buffer, 9999, 12, 31), my_printer);
    assert(strcmp(my_printer_buffer, "9999-12-31") == 0);

    date_print(date_init(&buffer, 0, 1, 1), my_printer);
    assert(strcmp(my_printer_buffer, "0000-01-01") == 0);
}

int main(void)
{
    require_that_valid_dates_can_be_initialized();
    require_that_invalid_date_cannot_be_initialized();
    require_that_dates_values_can_be_compared();
    require_that_dates_can_be_printed();
    puts("Unit tests OK");
    return 0;
}
