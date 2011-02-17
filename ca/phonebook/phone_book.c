#include "phone_book.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

phone_book * phone_book_create(size_t max_size) {
    phone_book * pb = malloc(sizeof(phone_book));
    pb->base = malloc(sizeof(struct phone_book_entry) * max_size);
    pb->max_size = max_size;
    
    for (size_t i=0; i<pb->max_size; ++i) 
        pb->base[i].in_use = false;

    return pb;
}

void phone_book_destroy(phone_book * pb) {
    free(pb->base);
    free(pb);
}

size_t phone_book_size(const phone_book * pb) {
    size_t count = 0;
    for (size_t i=0; i<pb->max_size; ++i)
        if (pb->base[i].in_use)
            count++;
    return count;
}

static phone_book_entry * find_first_unused_entry(phone_book * pb) {
    for (size_t i=0; i != pb->max_size; i++)
        if (!pb->base[i].in_use)
            return &pb->base[i];
    return 0;
}
    
bool phone_book_add(phone_book * pb, const char * name, const char * number) {
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

void phone_book_print_all(const phone_book * pb, void printer(const char *))
{
    printer("Phone book");
    printer("==========");
    for (size_t i=0; i != pb->max_size; i++) {
        phone_book_entry * pbe = &pb->base[i];
        if (pbe->in_use) {
            char str[256];
            sprintf(str, "%-20s %-18s", pbe->name, pbe->number);
            printer(str);
        }
    }
}
            
    
