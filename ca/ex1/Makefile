CC=gcc
CFLAGS=-std=c99 -g -Wall -Wextra -pedantic

all: phone_book_test phone_book_demo 

clean:
	rm -f phone_book_test phone_book_demo  
	rm -rf *.o a.out*

phone_book_test: phone_book_test.c phone_book.c
	$(CC) $(CFLAGS) -o $@ $^ && \
    ./$@; \
	rm $@

phone_book_demo: phone_book_demo.c phone_book.c
	$(CC) $(CFLAGS) -o $@ $^ && \
    ./$@; \
    rm $@

