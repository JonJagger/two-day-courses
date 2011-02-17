#include "phone_book.h"
#include <stdio.h>
#include <stdlib.h>

static const char * tf(bool value)
{
    return value ? "true" : "false";
}

int main(void)
{
    const size_t max_entries = 1024;
	phone_book * jjs = phone_book_create(max_entries);

    bool b1 = phone_book_add(jjs, "Jon Jagger", "11");
    printf("added Jon Jagger,111 --> %s\n", tf(b1));

    bool b2 = phone_book_add(jjs, "Donald Duck", "11");
    printf("added Donald Duck,11 --> %s\n", tf(b2));

    bool b3 = phone_book_add(jjs, "Olve Maudal", "22");
    printf("added Olve Maudal,22 --> %s\n", tf(b3));
 
    return 0;
}

