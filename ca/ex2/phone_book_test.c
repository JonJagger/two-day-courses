#include "phone_book.h"
#include <assert.h>
#include <string.h>

static void test_initialization(void)
{
    enum { max_phone_book_size = 99 };
    phone_book_entry entries[max_phone_book_size];
    phone_book pb;
    phone_book_init(&pb, entries, max_phone_book_size);
    assert( phone_book_size(&pb) == 0 );
}

static void test_adding_a_few_entries(void)
{
    enum { max_phone_book_size = 10 };
    phone_book_entry entries[max_phone_book_size];
    phone_book pb;
    phone_book_init(&pb, entries, max_phone_book_size);
    assert( phone_book_size(&pb) == 0 );
    
    assert( phone_book_add(&pb, "Olve", "5590093309") );
    assert( phone_book_size(&pb) == 1 );
    
    assert( phone_book_add(&pb, "Jon", "547967444782") );
    assert( phone_book_size(&pb) == 2 );

    assert( phone_book_add(&pb, "Olve Home", "5490093309") );
    assert( phone_book_size(&pb) == 3 );
}
    
static void test_containment(void)
{
    enum { max_phone_book_size = 10 };
    phone_book_entry entries[max_phone_book_size];
    phone_book pb;
    phone_book_init(&pb, entries, max_phone_book_size);

    assert( !phone_book_contains(&pb, "5590093309") );
    assert( phone_book_add(&pb, "Olve", "5590093309") );
    assert( phone_book_contains(&pb, "5590093309") );
}

static void test_removal(void)
{
    enum { max_phone_book_size = 10 };
    phone_book_entry entries[max_phone_book_size];
    phone_book pb;
    phone_book_init(&pb, entries, max_phone_book_size);

    assert( phone_book_add(&pb, "Olve", "5590093309") );
    assert( phone_book_size(&pb) == 1 );
    assert( phone_book_contains(&pb, "5590093309") );
    assert( phone_book_remove(&pb, "5590093309") );
    assert( !phone_book_contains(&pb, "5590093309") );
    assert( phone_book_size(&pb) == 0 );
}

static void test_duplicates(void)
{
    enum { max_phone_book_size = 10 };
    phone_book_entry entries[max_phone_book_size];
    phone_book pb;
    phone_book_init(&pb, entries, max_phone_book_size);

    assert( phone_book_add(&pb, "Olve", "5590093309") );
    assert( phone_book_size(&pb) == 1 );
    assert( !phone_book_add(&pb, "Olve (E20)", "5590093309") );
    assert( phone_book_size(&pb) == 1 );
}

static void test_fullness(void)
{
    enum { max_phone_book_size = 2 };
    phone_book_entry entries[max_phone_book_size];
    phone_book pb;
    phone_book_init(&pb, entries, max_phone_book_size);

    assert( phone_book_add(&pb, "Olve", "5590093309") );
    assert( phone_book_size(&pb) == 1 );
    assert( phone_book_add(&pb, "Jon", "547967444782") );
    assert( phone_book_size(&pb) == 2 );
    assert( !phone_book_add(&pb, "Olve Home", "5490093309") ); // full
    assert( phone_book_size(&pb) == 2 );
}

static void test_find(void)
{
    enum { max_phone_book_size = 10 };
    phone_book_entry entries[max_phone_book_size];
    phone_book pb;
    phone_book_init(&pb, entries, max_phone_book_size);
    phone_book_add(&pb, "Olve", "5590093309");
    phone_book_add(&pb, "Jon", "547967444782");
    phone_book_add(&pb, "Olve Home", "5490093309");

    assert( phone_book_find(&pb, "5490093309") );
    assert( !phone_book_find(&pb, "911") );
}

static void my_test_printer(const char * str)
{
    static int counter = 0;
    counter %= 2;
    if (counter == 0) 
        assert( strcmp(str, "Olve                                     5590093309") == 0 );
    else if (counter == 1)
        assert( strcmp(str, "Jon                                    547967444782") == 0 );
    counter++;
}

static void test_printing(void)
{
    enum { max_phone_book_size = 10 };
    phone_book_entry entries[max_phone_book_size];
    phone_book pb;
    phone_book_init(&pb, entries, max_phone_book_size);
    phone_book_add(&pb, "Olve", "5590093309");
    phone_book_add(&pb, "Jon", "547967444782");
    phone_book_print_all(&pb, my_test_printer);
}


int main(void)
{
    test_initialization();
    test_adding_a_few_entries();
    test_containment();
    test_removal();
    test_duplicates();
    test_fullness();
    test_find();
    test_printing();
}
