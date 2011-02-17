CC=gcc 
CFLAGS=-std=c99 -std=c99 -Wall -Wextra -pedantic 
LD=gcc

all: bitcount calcstat 

bitcount: bitcount_test.o bitcount_main.o bitcount.o
	$(LD) bitcount_test.o bitcount.o && ./a.out
	$(LD) -o bitcount bitcount_main.o bitcount.o

calcstat: calcstat_test.o calcstat_main.o calcstat.o
	$(LD) calcstat_test.o calcstat.o && ./a.out
	$(LD) -o calcstat calcstat_main.o calcstat.o

clean:
	rm -rf *.o a.out bitcount calcstat
