CC=g++ 
CPPFLAGS=-Wall -Wextra -pedantic -O2
LD=g++

all: date1_tests date2_tests date3_tests date1_demo date2_demo date3_demo date1_sortdemo date2_sortdemo date3_sortdemo
	
date1_demo: date1.o date1_demo.o
	$(LD) -o date1_demo $^

date1_sortdemo: date1.o date1_sortdemo.o
	$(LD) -o date1_sortdemo $^

date2_demo: date2.o date2_demo.o
	$(LD) -o date2_demo $^

date2_sortdemo: date2.o date2_sortdemo.o
	$(LD) -o date2_sortdemo $^

date3_demo: date3.o date3_demo.o
	$(LD) -o date3_demo $^

date3_sortdemo: date3.o date3_sortdemo.o
	$(LD) -o date3_sortdemo $^

date1_tests: date1_tests.o date1.o
	$(LD) $^ && ./a.out

date2_tests: date2_tests.o date2.o
	$(LD) $^ && ./a.out

date3_tests: date3_tests.o date3.o
	$(LD) $^ && ./a.out

date4_tests: date4_tests.o date4.o
	$(LD) $^ && ./a.out

htmlfiles:
	highlight -l -O html date1*.[ch]pp
	highlight -l -O html date2*.[ch]pp
	highlight -l -O html date3*.[ch]pp
	highlight --syntax=make -O html Makefile

clean:
	rm -rf *.o date[123]_demo date[123]_sortdemo a.out 
