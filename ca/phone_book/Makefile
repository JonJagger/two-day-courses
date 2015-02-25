CC=gcc
CFLAGS=-std=c99 -g -Wall -Wextra -pedantic

all: phone_book_test phone_book_demo phone_book_coverage phone_book_perf

clean:
	rm -f phone_book_test phone_book_demo phone_book_coverage phone_book_perf
	rm -rf *.o a.out* *.gcov *.gcda *.gcno

phone_book_test: phone_book_test.c phone_book.c
	$(CC) $(CFLAGS) -o $@ $^ && \
	valgrind -q ./$@; \
	rm $@

phone_book_demo: phone_book_demo.c phone_book.c
	$(CC) $(CFLAGS) -o $@ $^ && \
	valgrind -q ./$@; \
	rm $@

phone_book_coverage: phone_book_test.c phone_book.c
	$(CC) $(CFLAGS) -O0 -fprofile-arcs -ftest-coverage -o $@ $^ && \
	./$@; \
	gcov $^; \
	rm $@

phone_book_perf: phone_book_perf.c phone_book.c
	$(CC) $(CFLAGS) -O2 -pg -o $@ $^ && \
	time ./$@; \
	gprof $@; \
	rm $@
