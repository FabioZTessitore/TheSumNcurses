CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDLIBS=-lncurses

main: main.o quantity.o uiadapter.o

main.o: main.c quantity.h uiadapter.h
quantity.o: quantity.c quantity.h
uiadapter.o: uiadapter.c uiadapter.h quantity.h

.PHONY: clean
clean:
	rm -f *.o main
