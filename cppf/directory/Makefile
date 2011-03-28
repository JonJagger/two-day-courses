CC=g++ 
CPPFLAGS=-Wall -Wextra -pedantic -O2
LD=g++

all: directory_demo
	
directory_demo: directory_demo.o file.o directory.o 
	$(LD) -o directory_demo $^

clean:
	rm -rf *.o directory_demo a.out 

