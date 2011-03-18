CC=g++ 
CPPFLAGS=-Wall -Wextra -pedantic 
LD=g++

all: date1_tests date2_tests date3_tests
	

date1_tests: date1_tests.o date1.o
	$(LD) $^ && ./a.out

date2_tests: date2_tests.o date2.o
	$(LD) $^ && ./a.out

date3_tests: date3_tests.o date3.o
	$(LD) $^ && ./a.out

clean:
	rm -rf *.o a.out 
