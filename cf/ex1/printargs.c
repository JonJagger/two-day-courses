/* printargs.c */

#include <stdio.h>

int main(int argc, char * argv[])
{
    for (int at = 0; at != argc; ++at) 
        printf("argv[%d]=%s\n", at, argv[at]);
    return 0;
}
