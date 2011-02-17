#include "phone_book.h"
#include <assert.h>
#include <stdio.h>

static void my_printer(const char * message) 
{
    puts(message);
}

int main(void) {

    phone_book * pb = phone_book_create(9);
    assert( pb );
    assert( phone_book_size(pb) == 0 );
    phone_book_add(pb, "Olve", "90093309");
    assert( phone_book_size(pb) == 1 );
    phone_book_add(pb, "Katrina", "91809225");
    assert( phone_book_size(pb) == 2 );

    phone_book_print_all( pb, my_printer);

    phone_book_destroy(pb);
}

    
    
    
    
    
