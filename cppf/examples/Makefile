CXX=g++ 
CC=gcc
CXXFLAGS=-Wall -Wextra -pedantic -Weffc++ -Werror -O2 
CFLAGS=-std=c99 -Wall -Wextra -pedantic -Werror -O2 
LD=g++

#all: run_tests date_demo date_sortdemo directory_demo
	
all: lib/xyzlib.a lib/mylib.a bin/date_demo bin/date_sortdemo bin/directory_demo bin/demoall run_tests

#
# xyzlib archive
#

lib/xyzlib.a: xyzlib/xyzlib.o 
	ar -rcs lib/xyzlib.a xyzlib/xyzlib.o 

xyzlib/xyzlib.c: xyzlib/xyzlib.h

bin/xyzlib_tests: xyzlib/xyzlib_tests.o xyzlib/xyzlib.o
	$(LD) -o bin/xyzlib_tests $^

#
# mylib archive
#

lib/mylib.a: mylib/date.o mylib/file.o mylib/directory.o 
	ar -rcs lib/mylib.a $^

bin/date_tests: mylib/date_tests.o mylib/date.o lib/xyzlib.a
	$(LD) -o bin/date_tests $^

bin/recently_used_list_tests: mylib/recently_used_list_tests.o 
	$(LD) -o bin/recently_used_list_tests $^

mylib/directory_tests.o: mylib/directory_tests.cpp mylib/directory.hpp mylib/date.hpp mylib/directory_entry_visitor.hpp mylib/directory_entry.hpp

mylib/directory.o: mylib/directory.cpp mylib/directory.hpp mylib/file.hpp mylib/directory_entry.hpp mylib/directory_entry_visitor.hpp

mylib/file.o: mylib/file.cpp mylib/file.hpp mylib/directory_entry.hpp mylib/directory_entry_visitor.hpp

bin/directory_tests: mylib/directory_tests.o mylib/directory.o mylib/file.o mylib/date.o lib/xyzlib.a
	$(LD) -o bin/directory_tests $^

#
# demo
#

bin/date_demo: demo/date_demo.o lib/mylib.a lib/xyzlib.a
	$(LD) -o bin/date_demo $^

bin/date_sortdemo: demo/date_sortdemo.o lib/mylib.a lib/xyzlib.a
	$(LD) -o bin/date_sortdemo $^

bin/directory_demo: demo/directory_demo.o lib/mylib.a lib/xyzlib.a
	$(LD) -o bin/directory_demo $^

demo/demoall.cpp: mylib/recently_used_list.hpp mylib/file.hpp mylib/directory.hpp mylib/directory_entry.hpp xyzlib/xyzlib.h

bin/demoall: demo/demoall.o lib/mylib.a lib/xyzlib.a
	$(LD) -o bin/demoall $^

#
# tests
#

run_tests: bin/xyzlib_tests bin/date_tests bin/recently_used_list_tests bin/directory_tests
	bin/xyzlib_tests
	bin/date_tests 
	bin/recently_used_list_tests
	bin/directory_tests
	@echo "Tests OK"

clean:
	rm -f bin/* lib/* demo/*.o mylib/*.o xyzlib/*.o
