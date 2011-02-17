#ifndef PHONE_BOOK_H_INCLUDED
#define PHONE_BOOK_H_INCLUDED

#include <stddef.h>
#include <stdbool.h>

typedef struct phone_book phone_book;

phone_book * phone_book_create(size_t max_size);
size_t phone_book_size(const phone_book * pb);
void phone_book_destroy(phone_book * pb);
bool phone_book_add(phone_book * pb, const char * name, const char * number);
bool phone_book_contains(const phone_book * pb, const char * name, const char * number);
void phone_book_remove(phone_book * pb, const char * name, const char * number);
void phone_book_print_all(const phone_book * pb);

#endif
