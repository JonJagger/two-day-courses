#include "phone_book.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define SIZEOF_ARRAY(array) ( sizeof(array) / sizeof(array[0]) )

static void test_creating_a_zero_max_size_phone_book_fails(void)
{
    assert( phone_book_create(0) == NULL );
}

static void test_phone_book_can_be_created_and_destroyed(void)
{
    const size_t max_entries = 42;
	phone_book * pb = phone_book_create(max_entries);
    phone_book_destroy(pb);
}

static void test_added_entries_can_be_found_by_name(void)
{
    const size_t max_entries = 42;
	phone_book * pb = phone_book_create(max_entries);

    const char * jj_name = "Jon Jagger";
    const char * jj_number = "11";
    assert( phone_book_add(pb, jj_name, jj_number) );

    const char * bb_name = "Bert Bacharat";
    const char * bb_number = "22";
    assert( phone_book_add(pb, bb_name, bb_number) );

    const char * jj_found = phone_book_find_name(pb, jj_number);
    assert( jj_found );
    assert( strcmp(jj_found, jj_name) == 0 );

    const char * bb_found = phone_book_find_name(pb, bb_number);
    assert( bb_found );
    assert( strcmp(bb_found, bb_name) == 0);

    phone_book_destroy(pb);
}

static void test_added_entries_can_be_found_by_number(void)
{
    const size_t max_entries = 42;
	phone_book * pb = phone_book_create(max_entries);

    const char * jj_name = "Jon Jagger";
    const char * jj_number = "11";
    assert( phone_book_add(pb, jj_name, jj_number) );

    const char * bb_name = "Bert Bacharat";
    const char * bb_number = "22";
    assert( phone_book_add(pb, bb_name, bb_number) );

    const char * jj_found = phone_book_find_number(pb, jj_name);
    assert( jj_found );
    assert( strcmp(jj_found, jj_number) == 0 );

    const char * bb_found = phone_book_find_number(pb, bb_name);
    assert( bb_found );
    assert( strcmp(bb_found, bb_number) == 0);

    phone_book_destroy(pb);
}

static void test_entries_not_added_are_not_found_by_name(void)
{
    const size_t max_entries = 42;
	phone_book * pb = phone_book_create(max_entries);

    assert( !phone_book_find_name(pb, "123") );
    assert( phone_book_add(pb, "Jon Jagger", "123") );
    assert( !phone_book_find_name(pb, "43345") );

    phone_book_destroy(pb);
}

static void test_entries_not_added_are_not_found_by_number(void)
{
    const size_t max_entries = 42;
	phone_book * pb = phone_book_create(max_entries);

    assert( !phone_book_find_number(pb, "123") );
    assert( phone_book_add(pb, "Jon Jagger", "123") );
    assert( !phone_book_find_number(pb, "43345") );

    phone_book_destroy(pb);
}

static void test_unreachable_numbers_cannot_be_added(void)
{
    const size_t max_entries = 42;
	phone_book * pb = phone_book_create(max_entries);

    assert( phone_book_add(pb, "Alan Alda", "1443") );
    assert( phone_book_add(pb, "Jon Jagger", "11") );
    assert( !phone_book_add(pb, "Bert Bacharat", "1") );
    assert( !phone_book_add(pb, "Bert Bacharat", "111") );

    phone_book_destroy(pb);
}

static void test_unreachablility_does_not_apply_to_names(void)
{
    const size_t max_entries = 42;
	phone_book * pb = phone_book_create(max_entries);

    assert( phone_book_add(pb, "Jon Jagger",          "234") );
    assert( phone_book_add(pb, "Jon Jagger (mobile)", "123") );

    phone_book_destroy(pb);
}

struct name_and_number
{
    const char * name;
    const char * number;
};
typedef struct name_and_number name_and_number;

static const name_and_number persons[] =
{
    { .name = "Olve",   .number = "456" },
    { .name = "Espen",  .number = "678" },
    { .name = "Jon",    .number = "422" },
    { .name = "Harald", .number = "1458" },
};

static void test_by_name_printer(const char * name, const char * number)
{
    static size_t pos = 0;
    static const size_t index[SIZEOF_ARRAY(persons)] = { 1, 3, 2, 0 };
    const name_and_number * person = &persons[index[pos]];
    assert( strcmp(person->name, name) == 0 );
    assert( strcmp(person->number, number) == 0 );
    pos++;
    pos %= SIZEOF_ARRAY(persons);
}

static void test_print_by_name(void)
{
    const size_t max_entries = 42;
	phone_book * pb = phone_book_create(max_entries);
    for (size_t at = 0; at != SIZEOF_ARRAY(persons); at++)
    {
        const name_and_number * person = &persons[at];
        phone_book_add(pb, person->name, person->number);
    }
    phone_book_print_by_name(pb, test_by_name_printer);
    phone_book_destroy(pb);
}

static void test_by_number_printer(const char * name, const char * number)
{
    static size_t pos = 0;
    static const size_t index[SIZEOF_ARRAY(persons)] = { 3, 2, 0, 1, };
    const name_and_number * person = &persons[index[pos]];
    assert( strcmp(person->name, name) == 0 );
    assert( strcmp(person->number, number) == 0 );
    pos++;
    pos %= SIZEOF_ARRAY(persons);
}

static void test_print_by_number(void)
{
    const size_t max_entries = 42;
	phone_book * pb = phone_book_create(max_entries);
    for (size_t at = 0; at != SIZEOF_ARRAY(persons); at++)
    {
        const name_and_number * person = &persons[at];
        phone_book_add(pb, person->name, person->number);
    }
    phone_book_print_by_number(pb, test_by_number_printer);

    phone_book_destroy(pb);
}

static void test_removed_entries_cannot_be_found_by_name(void)
{
    const size_t max_entries = 42;
	phone_book * pb = phone_book_create(max_entries);
    phone_book_add(pb, "Jon Jagger", "123");
    assert ( phone_book_remove(pb, "123") );
    assert( phone_book_find_name(pb, "123") == NULL);
    phone_book_destroy(pb);
}

static void test_removed_entries_cannot_be_found_by_number(void)
{
    const size_t max_entries = 42;
	phone_book * pb = phone_book_create(max_entries);
    phone_book_add(pb, "Jon Jagger", "123");
    phone_book_add(pb, "Olve Maudal", "456");

    assert ( phone_book_remove(pb, "123") );
    assert( phone_book_find_number(pb, "Jon Jagger") == NULL);
    phone_book_destroy(pb);
}

int main(void)
{
    test_creating_a_zero_max_size_phone_book_fails();
    test_phone_book_can_be_created_and_destroyed();

    test_added_entries_can_be_found_by_name();
    test_added_entries_can_be_found_by_number();

    test_entries_not_added_are_not_found_by_name();
    test_entries_not_added_are_not_found_by_number();

    test_unreachable_numbers_cannot_be_added();
    test_unreachablility_does_not_apply_to_names();

    test_print_by_name();
    test_print_by_number();

    test_removed_entries_cannot_be_found_by_name();
    test_removed_entries_cannot_be_found_by_number();

    return 0;
}


