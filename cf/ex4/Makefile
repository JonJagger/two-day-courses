CC=gcc 
CFLAGS=-std=c99 -std=c99 -Wall -Wextra -pedantic 
LD=gcc

all: date date2 usedate usedate2

date: date_test.o date_main.o date.o
	$(LD) date_test.o date.o && ./a.out
	$(LD) -o date date_main.o date.o

date2: date2_test.o date2_main.o date2.o
	$(LD) date2_test.o date2.o && ./a.out
	$(LD) -o date2 date2_main.o date2.o

usedate: usedate.o date.o
	$(LD) $^ && ./a.out

usedate2: usedate2.o date2.o
	$(LD) $^ && ./a.out

clean:
	rm -rf *.o a.out date date2 
