#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int compare(const void * a, const void * b)
{
    return strcmp(*(char**)a, *(char**)b);
}
    
int main(int argc, char * argv[])
{
    size_t i;
    qsort(argv, argc, sizeof *argv, compare);
    for (i=0; i<argc; i++)
        puts(argv[i]);
    return 0;
}
