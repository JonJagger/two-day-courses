#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int compare(const void * a, const void * b)
{
    return strcmp(*(char**)a, *(char**)b);
}
    
int main(int argc, char * argv[])
{
    qsort(argv, argc, sizeof *argv, compare);
    for (int i = 0; i < argc; i++)
        puts(argv[i]);
    return 0;
}
