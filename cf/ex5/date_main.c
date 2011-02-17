#include "date.h"
#include <stdio.h>
#include <stdlib.h>

static void my_printer(const char * message) 
{
    puts(message);
}

static void demo_print(const char * name, const date * when)
{
	puts(name);
	puts(" = ");
	date_print(when, my_printer);
}

static void demo_compare(const char * lhs_name, const date * lhs,
						 const char * rhs_name, const date * rhs)
{
    printf("%s == %s ? %s\n",
		lhs_name, rhs_name, date_equal(lhs, rhs) ? "true" : "false");
}

int main(void) 
{
    static date global;
	date local;
	date * dynamic = (date *)malloc(sizeof(*dynamic));

    date_init(&global, 2008, 3, 6);
    date_init(&local,  2008, 3, 6);
    date_init(dynamic, 2008, 3, 7);

	demo_print("global",  &global);
	demo_print("local",   &local);
	demo_print("dynamic", dynamic);

	demo_compare("global", &global, "local", &local);
	demo_compare("local", &local, "dynamic", dynamic);

    free(dynamic);

	return 0;
}
