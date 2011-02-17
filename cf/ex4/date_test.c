/* date_test.c */

#include "date.h"

#include <assert.h>
#include <string.h>
#include <stdio.h>

static void require_that_valid_dates_can_be_created(void) 
{
    struct date * when;

    when = date_create(2008, 2, 29);
    assert(when != NULL);
    date_destroy(when);
    
    when = date_create(2008, 3, 6);
    assert(when != NULL);
    date_destroy(when);

    when = date_create(0, 1, 1);
    assert(when != NULL);
    date_destroy(when);

    when = date_create(9999, 12, 31);
    assert(when != NULL);
    date_destroy(when);
}

static void require_that_invalid_date_can_not_be_created(void) 
{
    assert(date_create(10000, 3, 6) == NULL );
    assert(date_create(-1, 3, 6) == NULL );

    assert(date_create(2008, 13, 6) == NULL);
    assert(date_create(2008, 0, 6) == NULL);
    
    assert(date_create(2008, 3, 32) == NULL);
    assert(date_create(2008, 3, 0) == NULL);
    
    assert(date_create(2008,2,30) == NULL);
    assert(date_create(2007,2,29) == NULL);
}

static void require_that_dates_values_can_be_compared(void) 
{
    struct date * d1 = date_create(2008, 3, 6);
    struct date * d2 = date_create(2008, 3, 6);
    struct date * d3 = date_create(2008, 3, 7);
    
    assert(date_equal(d1, d1));
    assert(date_equal(d1, d2));
    assert(!date_equal(d1, d3));
    
    date_destroy(d3);
    date_destroy(d2);
    date_destroy(d1);
}

static char my_printer_buffer[1024];

static void my_printer(const char * message) 
{
    strncpy(my_printer_buffer, message, sizeof(my_printer_buffer));
    my_printer_buffer[sizeof(my_printer_buffer) - 1] = '\0';
}

static void require_that_dates_can_be_printed(void) 
{
    struct date * d1 = date_create(2008,3,6);
    struct date * d2 = date_create(9999,12,31);
    struct date * d3 = date_create(0,1,1);

    date_print(d1, my_printer);
    assert( !strcmp(my_printer_buffer, "2008-03-06") );
    date_print(d2, my_printer);
    assert( !strcmp(my_printer_buffer, "9999-12-31") );
    date_print(d3, my_printer);
    assert( !strcmp(my_printer_buffer, "0000-01-01") );

    date_destroy(d3);
    date_destroy(d2);
    date_destroy(d1);
}

static void require_that_max_dates_can_be_allocated_and_released(void) 
{
    enum { date_pool_size = 16 }; // must be the same value as in date.c
    
    struct date * dates[date_pool_size]; 

    for (int i = 0; i != date_pool_size; i++) {
        dates[i] = date_create(2008, 3, 6);
        assert(dates[i] != NULL);
    }
    
    assert(date_create(2008, 3, 6) == NULL);
    for (int i = 0; i != date_pool_size; i++) {
        date_destroy(dates[i]);
    }
    
    for (int i = 0; i != date_pool_size; i++) {
        dates[i] = date_create(2008, 3, 6);
        assert(dates[i] != NULL);
    }
    
    for (int i = 0; i != date_pool_size; i++) {
        date_destroy(dates[i]);
    }
}


int main(void)
{
    require_that_valid_dates_can_be_created();
    require_that_invalid_date_can_not_be_created();
    require_that_dates_values_can_be_compared();
    require_that_dates_can_be_printed();
    require_that_max_dates_can_be_allocated_and_released();
    puts("Unit tests OK");
    return 0;
}
