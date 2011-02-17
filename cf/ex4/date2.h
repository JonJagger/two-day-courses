#ifndef DATE2_INCLUDED
#define DATE2_INCLUDED

#include <stdbool.h>

typedef struct date date;

enum { size_of_date = 12 };

date * date_init(void * rawmem, int year, int month, int day);
bool date_equal(const date *, const date *);
void date_print(const date *, void printer(const char *));

#endif
