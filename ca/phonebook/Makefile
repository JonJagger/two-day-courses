CC=gcc 
CFLAGS=-std=c99 -std=c99 -Wall -Wextra -pedantic 
LD=gcc

all: phone_book_test

phone_book.o: phone_book.c phone_book.h

phone_book_test.o: phone_book_test.c

phone_book_test: phone_book_test.o phone_book.o
	$(LD) phone_book_test.o phone_book.o && ./a.out

clean:
	rm -rf *.o a.out 
