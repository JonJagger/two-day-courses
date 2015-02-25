#ifndef PHONE_BOOK_INCLUDED
#define PHONE_BOOK_INCLUDED

#include <stdbool.h>
#include <stddef.h>

typedef struct phone_book phone_book;

phone_book * phone_book_create(size_t max_size);
void         phone_book_destroy(phone_book *);

bool phone_book_add(phone_book *, const char * name, const char * number);
bool phone_book_remove(phone_book *, const char * number);

const char * phone_book_find_number(const phone_book *, const char * name);
const char * phone_book_find_name(const phone_book *, const char * number);

//size_t phone_book_size(const phone_book * pb);
//bool phone_book_full(const phone_book * pb);

void phone_book_print_by_name(const phone_book *, void print(const char * name, const char * number));
void phone_book_print_by_number(const phone_book *, void print(const char * name, const char * number));

void phone_book_dump(const phone_book * pb);

#endif
