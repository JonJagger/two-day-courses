
//-------------------------------

typedef union
{
   char c;
   short s;
   int i;
   long l;
   long long ll;
   float f;
   double d;
   long double ld;
   void * op;
} aligned;

#define ENOUGH_FOR(type)    \
	(size_of_a_ ## type / sizeof(aligned) + 1)

//-------------------------------
// wibble.h
#include <stdio.h>

typedef struct wibble wibble;
enum { size_of_a_wibble = 16 };

wibble * wibble_init(aligned * memory);
int wibble_fprintf(FILE * stream, wibble * ptr);

//--------------------------------

int main(void)
{
    aligned memory[ENOUGH_FOR(wibble)];
    wibble * x = wibble_init(memory);

    wibble_fprintf(stdout, x);

    return 0;
}

//---------------------------------
// wibble.c

struct wibble
{
   int a,b,c,d;
};

// some stuff for doing compile time assertions
// in c that would be in its own header file
// such as cta.h 

#define COMPILE_TIME_ASSERTION(assertion) \
    static char CONCAT2(_m_,__LINE__) [ assertion ]

#define CONCAT2(a,b) CONCAT1(a,b)

#define CONCAT1(a,b) a ## b

#define SIZE_ASSERTION(type) \
    COMPILE_TIME_ASSERTION(sizeof(type) == size_of_a_ ## type)

// allowing a compile time check that
// size_of_a_wibble from wibble.h == sizeof(wibble)
SIZE_ASSERTION(wibble);

wibble * wibble_init(aligned * memory)
{
    wibble * ptr = (wibble *)memory;
    ptr->a = 0;
    ptr->b = 1;
    ptr->c = 2;
    return ptr;
}

int wibble_fprintf(FILE * stream, wibble * ptr)
{
    return fprintf(stream, "[%d:%d:%d]",
	ptr->a, ptr->b, ptr->c);
}


