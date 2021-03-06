all: prog

prog: main.o fonctions.o
	gcc -o $@ main.o fonctions.o

main.o: main.c fonctions.h
	gcc -Wall -o main.o -c main.c

fonctions.o: fonctions.c
	gcc -Wall -o fonctions.o -c $^

test : prog
	@echo "*** TESTING : ***\n"
	./prog

clean:
	rm -r *.o
