CC=g++ 
CFLAGS=-Wall -Wextra -pedantic 
LD=g++

all: recently_used_list_tests
	

recently_used_list_tests: recently_used_list_tests.o recently_used_list.o
	$(LD) $^ && ./a.out

clean:
	rm -rf *.o a.out recently_used_list_tests
