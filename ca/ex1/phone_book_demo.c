#include "phone_book.h"

int main(void)
{
    phone_book * pb = phone_book_create(9);
    phone_book_add(pb, "Olve", "5590093309");
    phone_book_add(pb, "Jon", "547967444782");
    phone_book_print_all(pb);
    phone_book_destroy(pb);
}
