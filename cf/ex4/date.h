#ifndef DATE_INCLUDED
#define DATE_INCLUDED

#include <stdbool.h>

typedef struct date date;

date * date_create(int year, int month, int day);
void date_destroy(date *);
bool date_equal(const date *, const date *);
void date_print(const date *, void printer(const char *));

#endif
