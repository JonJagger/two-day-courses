all: printargs hello

printargs: printargs.c
	gcc -std=c99 -Wall -Wextra -pedantic printargs.c -o printargs

hello: hello.c
	gcc -std=c99 -Wall -Wextra -pedantic hello.c -o hello

clean:
	rm -rf hello printargs

