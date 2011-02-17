CC=gcc 
CFLAGS=-std=c99 -std=c99 -Wall -Wextra -pedantic 
LD=gcc

all: addvec date

addvec: addvec_main.o addvec.o
	$(LD) -o $@ $^

date: date_main.o date.o
	$(LD) -o $@ $^

clean:
	rm -rf *.o addvec date
