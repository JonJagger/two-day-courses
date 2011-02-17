/* printvalues.c */

#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    if (argc != 2) {
        puts("usage: printvalues file");
        return argc == 1 ? EXIT_SUCCESS : EXIT_FAILURE;
    }

    const char * filename = argv[1];
    FILE * fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "unable to open %s: %s", filename,
                strerror(errno));
        return EXIT_FAILURE;
    }

    int value;
    while( fscanf(fp, "%d", &value) == 1 ) 
        printf("%d\n", value);
    
    fclose(fp);
    return EXIT_SUCCESS;
}
