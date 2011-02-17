#include "phone_book.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_PHONE_NUMBER_LEN 15
#define MAX_PHONE_NAME_LEN 64

typedef struct 
{
    bool in_use;
    char number[MAX_PHONE_NUMBER_LEN+1];
    char name[MAX_PHONE_NAME_LEN+1];
} phone_book_entry;

struct phone_book
{
    phone_book_entry * entries;
    size_t max_size;
};

phone_book * phone_book_create(size_t max_size)
{
    phone_book * pb = malloc(sizeof(phone_book));
    pb->entries = malloc(sizeof(phone_book_entry) * max_size);
    pb->max_size = max_size;
    
    for (size_t at = 0; at != pb->max_size; at++) 
        pb->entries[at].in_use = false;

    return pb;
}

void phone_book_destroy(phone_book * pb)
{
    free(pb->entries);
    free(pb);
}

size_t phone_book_size(const phone_book * pb)
{
    size_t count = 0;
    for (size_t at = 0; at != pb->max_size; at++)
        if (pb->entries[at].in_use)
            count++;
    return count;
}

static phone_book_entry * find_first_unused_entry(const phone_book * pb)
{
    for (size_t at = 0; at != pb->max_size; at++)
        if (!pb->entries[at].in_use)
            return &pb->entries[at];
    return 0;
}
    
bool phone_book_add(phone_book * pb, const char * name, const char * number)
{
    phone_book_entry * pbe = find_first_unused_entry(pb);
    if (!pbe)
        return false;
    pbe->in_use = true;
    strncpy(pbe->name, name, MAX_PHONE_NAME_LEN);
    pbe->name[MAX_PHONE_NAME_LEN] = '\0';
    strncpy(pbe->number, number, MAX_PHONE_NUMBER_LEN);
    pbe->name[MAX_PHONE_NUMBER_LEN] = '\0';
    return true;
}

static bool equals(const phone_book_entry * pbe, const char * name, const char * number)
{
    return pbe->in_use && strcmp(pbe->name, name) == 0 && strcmp(pbe->number, number) == 0;
}

static phone_book_entry * find(const phone_book * pb, const char * name, const char * number)
{
    size_t at = 0;
    while (at != pb->max_size && !equals(&pb->entries[at], name, number))
        at++;
    return at != pb->max_size ? &pb->entries[at] : 0;
}

bool phone_book_contains(const phone_book * pb, const char * name, const char * number)
{
    return find(pb, name, number);
}

void phone_book_remove(phone_book * pb, const char * name, const char * number)
{
    phone_book_entry * found = find(pb, name, number);
    if (found) 
        found->in_use = false;
}

void phone_book_print_all(const phone_book * pb)
{
    puts("Phone book");
    puts("==========");
    for (size_t at = 0; at != pb->max_size; at++)
    {
        const phone_book_entry * pbe = &pb->entries[at];
        if (pbe->in_use) 
            printf("%-20s %-18s\n", pbe->name, pbe->number);
    }
}
            
    
