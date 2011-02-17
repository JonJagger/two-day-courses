/* bitcount.c */

#include "bitcount.h"

#include <stdio.h>
#include <stdlib.h>

void check_usage(int argc, char * argv[])
{
    if (argc < 2) 
    {
        printf("usage: %s value\n", argv[0]);
        exit(0);
    }
}

int main(int argc, char * argv[])
{
    check_usage(argc, argv);
    unsigned int value = atoi(argv[1]);
    printf("%d\n", bitcount(value));
    return 0;
}
