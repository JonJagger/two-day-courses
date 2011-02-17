#include "phone_book.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void phone_book_init(phone_book * pb, phone_book_entry * entries, size_t max_size)
{
    pb->entries = entries;
    pb->max_size = max_size;

    for (size_t at = 0; at != pb->max_size; at++) 
        pb->entries[at].in_use = false;
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

static bool equals_number(const phone_book_entry * pbe, const char * number)
{
    return pbe->in_use && strcmp(pbe->number, number) == 0;
}

phone_book_entry * phone_book_find(const phone_book * pb, const char * number)
{
    size_t at = 0;
    while (at != pb->max_size && !equals_number(&pb->entries[at], number))
        at++;
    return at != pb->max_size ? &pb->entries[at] : 0;
}

bool phone_book_add(phone_book * pb, const char * name, const char * number)
{
    if (phone_book_find(pb, number))
        return false;
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

bool phone_book_contains(const phone_book * pb, const char * number)
{
    return phone_book_find(pb, number); 
}

bool phone_book_remove(phone_book * pb, const char * number)
{
    phone_book_entry * found = phone_book_find(pb, number);
    if (found) 
        found->in_use = false;
    return found;
}

void phone_book_print_all(const phone_book * pb, void printer(const char *))
{
    for (size_t at = 0; at != pb->max_size; at++)
    {
        const phone_book_entry * pbe = &pb->entries[at];
        if (pbe->in_use)
        {
            char str[256];
            sprintf(str,"%-32s %18s", pbe->name, pbe->number);
            printer(str);
        }
    }
}
