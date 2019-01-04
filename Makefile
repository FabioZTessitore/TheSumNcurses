CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDLIBS=

main: main.o quantity.o

main.o: main.c quantity.h
quantity.o: quantity.c quantity.h

.PHONY: clean
clean:
	rm -f *.o main
