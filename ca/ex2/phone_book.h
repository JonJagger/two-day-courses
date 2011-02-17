#ifndef PHONE_BOOK_H_INCLUDED
#define PHONE_BOOK_H_INCLUDED

#include <stdbool.h>
#include <stddef.h>

#define MAX_PHONE_NUMBER_LEN 15
#define MAX_PHONE_NAME_LEN 64

struct phone_book_entry
{
    bool in_use;
    char number[MAX_PHONE_NUMBER_LEN+1];
    char name[MAX_PHONE_NAME_LEN+1];
};

typedef struct phone_book_entry phone_book_entry;

struct phone_book
{
    phone_book_entry * entries;
    size_t max_size;
};

typedef struct phone_book phone_book;

//modifiers
void phone_book_init(phone_book * pb, phone_book_entry * entries, size_t max_size);
bool phone_book_add(phone_book * pb, const char * name, const char * number);
bool phone_book_remove(phone_book * pb, const char * number);

//queries
size_t phone_book_size(const phone_book * pb);
bool phone_book_contains(const phone_book * pb, const char * number);
phone_book_entry * phone_book_find(const phone_book * pb, const char * number);
void phone_book_print_all(const phone_book * pb, void printer(const char *));

#endif
