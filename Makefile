CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDLIBS=-lncurses

main: main.o quantity.o quantity_ui.o uiadapter.o subject.o observer.o

main.o: main.c quantity.h uiadapter.h
quantity.o: quantity.c quantity.h subject.h
quantity_ui.o: quantity_ui.c quantity_ui.h quantity.h
uiadapter.o: uiadapter.c uiadapter.h quantity.h quantity_ui.h observer.h
subject.o: subject.c subject.h observer.h
observer.o: observer.c observer.h

.PHONY: clean
clean:
	rm -f *.o main
