#include "date.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct date date;

const date global = { 2008, 3, 6 };

int main(void)
{
    printf("global = ");
    date_print(&global);

    const date local = { 2008, 3, 6 };
    printf("local = ");
    date_print(&local);

    date * const dynamic = (date *)malloc(sizeof(*dynamic));
    dynamic->year = 2008;
    dynamic->month = 3;
    dynamic->day = 8;

    printf("dynamic = ");
    date_print(dynamic);

    printf("global and local are %sequal\n",
           date_equal(&global, &local) ? "" : "not ");

    printf("global and dynamic are %sequal\n",
           date_equal(&global, dynamic) ? "" : "not ");

    free(dynamic);

    return 0;
}
