CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDLIBS=-lncurses

main: main.o quantity.o quantity_ui.o uiadapter.o

main.o: main.c quantity.h uiadapter.h
quantity.o: quantity.c quantity.h
quantity_ui.o: quantity_ui.c quantity_ui.h quantity.h
uiadapter.o: uiadapter.c uiadapter.h quantity.h quantity_ui.h

.PHONY: clean
clean:
	rm -f *.o main
