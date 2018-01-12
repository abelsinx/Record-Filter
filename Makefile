
all: RecFil.o node.o
	gcc -o recfil RecFil.o node.o
	rm RecFil.o node.o

RecFil.o: RecFil.c node.o
	gcc -c RecFil.c

node.o: node.c node.h
	gcc -c node.c




