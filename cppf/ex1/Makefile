CC=g++ 
CPPFLAGS=-Wall -Wextra -pedantic 
LD=g++

all: hello argsort1 argsort2

hello: hello.o
	$(LD) -o hello $^

argsort1: argsort1.o
	$(LD) -o argsort1 -O $^

argsort2: argsort2.o
	$(LD) -o argsort2 -O $^

runtests: hello argsort1 argsort2
	@./hello
	@./argsort1 foo bar gaz
	@./argsort2 foo bar gaz

clean:
	rm -rf *.o a.out hello argsort1 argsort2
