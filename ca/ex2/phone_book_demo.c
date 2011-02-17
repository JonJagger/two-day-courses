#include "phone_book.h"
#include <stdio.h>

static void my_printer(const char * str)
{
    puts(str);
}

int main(void)
{
    phone_book_entry entries[512];
    phone_book pb;
    phone_book_init(&pb, entries, 512);
    phone_book_add(&pb, "Olve", "5590093309");
    phone_book_add(&pb, "Jon", "547967444782");
    phone_book_print_all(&pb, my_printer);
}
