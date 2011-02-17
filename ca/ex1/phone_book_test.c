#include "phone_book.h"
#include <assert.h>

int main(void)
{
    phone_book * pb = phone_book_create(9);
    assert( pb );
    assert( phone_book_size(pb) == 0 );
    phone_book_add(pb, "Olve", "90093309");
    assert( phone_book_size(pb) == 1 );
    phone_book_add(pb, "Jon", "547967444782");
    assert( phone_book_size(pb) == 2 );
    assert( phone_book_contains(pb, "Jon", "547967444782") );
    phone_book_remove(pb, "Jon", "547967444782");
    assert( !phone_book_contains(pb, "Jon", "547967444782") );
    assert( phone_book_size(pb) == 1 );
    phone_book_destroy(pb);
}

    
    
    
    
    
