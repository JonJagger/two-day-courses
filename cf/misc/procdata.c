/*
 * C Foundation Cookbook
 *
 * How to read command line arguments
 */ 

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

static const char * usage_hint = "(try -u or --help)";
static const char * help_text =
    "usage: procdata [options] file...\n"
    "\n"
    "options:\n"
    "  -r, --reverse     reverse output\n"
    "  -q, --quiet       be quiet\n"
    "  -v, --verbose     verbose mode (repeat for more verbosity)\n"
    "  -P, --prefix=STR  prefix all lines with STR\n"
    "  -u, --help        give this help\n"
    "\n"
    "examples:\n"
    "  procdata -f -q foo.dat bar.dat\n";

int main(int argc, char * argv[]) {
    
    if ( argc == 1 ) {
        printf("usage: procdata [-vu] [-P prefix] file... %s\n", usage_hint);
        exit(EXIT_SUCCESS);
    }

    bool reverse = false;
    int verbosity = 1;
    const char * prefix = "";

    int i=1;
    while ( i < argc && argv[i][0] == '-' ) {
        if ( strcmp(argv[i],"-u") == 0 ||
             strcmp(argv[i],"--help") == 0 ) {
            puts(help_text);
            exit(EXIT_SUCCESS);
        } else if ( strcmp(argv[i],"-r") == 0 ||
                    strcmp(argv[i],"--reverse") == 0 ) {
            reverse = true;
        } else if ( strcmp(argv[i],"-q") == 0 ||
                    strcmp(argv[i],"--quiet") == 0 ) {
            verbosity--;
        } else if ( strcmp(argv[i],"-v") == 0 ||
                    strcmp(argv[i],"--verbose") == 0 ) {
            verbosity++;
        } else if ( strcmp(argv[i],"-P") == 0 ) {
            if ( ++i == argc ) {
                fprintf(stderr,"expected an argument to -P %s\n", usage_hint);
                exit(EXIT_FAILURE);
            }
            prefix = argv[i];
        } else if ( strstr(argv[i],"--prefix=") == argv[i] ) {
            prefix = argv[i] + strlen("--prefix=");
        } else {
            fprintf(stderr,"illegal option: %s %s\n", argv[i], usage_hint);
            exit(EXIT_FAILURE);
        }
        i++;
    }

    if ( i == argc ) {
        fprintf(stderr, "expected one or more input files %s\n", usage_hint);
        exit(EXIT_FAILURE);
    }

    if ( verbosity > 1 ) {
        printf("options:\n");
        printf("  reverse = %s\n", reverse ? "true" : "false" );
        printf("  verbosity = %d\n", verbosity);
        printf("  prefix = %s\n", prefix);
    };

    if ( verbosity > 0 ) 
        printf("processing file:\n");

    for ( int j=0; j<argc-i; j++ ) {
        char * filename = argv[reverse?(argc-j-1):(i+j)];
        if ( verbosity > 0 ) 
            printf("  %s%s\n", prefix, filename);
    }
    
    exit(EXIT_SUCCESS);
}
