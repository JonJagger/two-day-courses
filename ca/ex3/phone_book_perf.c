#include "phone_book.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const size_t n_entries = 1000;
    phone_book * pb = phone_book_create(n_entries);
    for (size_t i = 0; i != n_entries; i++) 
    {
        char name[20];
        sprintf(name, "Name%zd", i);
        char number[20];
        sprintf(number, "%d%zd", rand() % 1000, i);
        phone_book_add(pb, name, number);
    }
    phone_book_destroy(pb);
}
