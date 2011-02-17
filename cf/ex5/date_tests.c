#include "date.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

static void require_valid_date_can_be_initialized(void) 
{
    date when;
    assert(date_init(&when, 2008, 2, 29));
    assert(date_init(&when, 2008, 3, 6));
    assert(date_init(&when, 0, 1, 1));
    assert(date_init(&when, 9999, 12, 31));
}

static void require_invalid_date_cannot_be_initialized(void) 
{
    date when;
    assert(!date_init(&when, 10000, 3, 6));
    assert(!date_init(&when, -1, 3, 6));
    assert(!date_init(&when, 2008, 13, 6));
    assert(!date_init(&when, 2008, 0, 6));
    assert(!date_init(&when, 2008, 3, 32));
    assert(!date_init(&when, 2008, 3, 0));
    assert(!date_init(&when, 2008, 2, 30));
    assert(!date_init(&when, 2007, 2, 29));
}

static void require_date_equality(void) 
{
    date d1, d2, d3;    
    date_init(&d1, 2008, 3, 6);
    date_init(&d2, 2008, 3, 6);
    date_init(&d3, 2008, 3, 7);
    
    assert(date_equal(&d1, &d1));
    assert(date_equal(&d1, &d2));
    assert(!date_equal(&d1, &d3));
}

static char my_printer_buffer[1024];

static void my_printer(const char * message) 
{
    strncpy(my_printer_buffer, message, sizeof(my_printer_buffer));
    my_printer_buffer[sizeof(my_printer_buffer) - 1] = '\0';
}

static void require_date_printing(void) 
{
    date when;

    date_init(&when, 2008, 3, 6);
    date_print(&when, my_printer);
    assert(strcmp(my_printer_buffer, "2008/03/06") == 0);

    date_init(&when, 9999, 12, 31);
    date_print(&when, my_printer);
    assert(strcmp(my_printer_buffer, "9999/12/31") == 0);

    date_init(&when, 0, 1, 1);
    date_print(&when, my_printer);
    assert(strcmp(my_printer_buffer, "0000/01/01") == 0);
}

static void require_date_year_accessor(void)
{
    date when;
    date_init(&when, 2008, 3, 31);
    assert(date_year(&when) == 2008);
}

static void require_date_month_accessor(void)
{
    date when;
    date_init(&when, 2008, 3, 31);
    assert(date_month(&when) == 3);
}

static void require_date_day_accessor(void)
{
    date when;
    date_init(&when, 2008, 3, 31);
    assert(date_day(&when) == 31);
}

int main(void)
{
    require_valid_date_can_be_initialized();
    require_invalid_date_cannot_be_initialized();
    require_date_equality();
    require_date_printing();
    require_date_year_accessor();
    require_date_month_accessor();
    require_date_day_accessor();

    puts("Unit tests OK");
    return 0;
}
