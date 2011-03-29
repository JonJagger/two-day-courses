CC=g++ 
CPPFLAGS=-Wall -Wextra -pedantic -O2
LD=g++

all: folderdemo
	
folderdemo: folderdemo.o file.o directory.o date.o
	$(LD) -o folderdemo $^

clean:
	rm -rf *.o folderdemo a.out 

