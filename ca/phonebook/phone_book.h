#ifndef PHONE_BOOK_H_INCLUDED
#define PHONE_BOOK_H_INCLUDED

#include <stddef.h>
#include <stdbool.h>

#define MAX_PHONE_NUMBER_LEN 12
#define MAX_PHONE_NAME_LEN 36

struct phone_book_entry {
    bool in_use;
    char number[MAX_PHONE_NUMBER_LEN+1];
    char name[MAX_PHONE_NAME_LEN+1];
};

typedef struct phone_book_entry phone_book_entry;

struct phone_book {
    phone_book_entry * base;
    size_t max_size;
};

typedef struct phone_book phone_book;

phone_book * phone_book_create(size_t max_size);
size_t phone_book_size(const phone_book * pb);

void phone_book_destroy(phone_book * pb);
bool phone_book_add(phone_book * pb, const char * name, const char * number);

void phone_book_print_all(const phone_book * pb, void printer(const char *));

#endif
