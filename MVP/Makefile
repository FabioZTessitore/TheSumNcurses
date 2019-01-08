CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDLIBS=-lncurses

main: main.o quantity.o quantity_ui.o uiadapter.o ioadapter.o iotxtfile.o presenter.o subject.o observer.o

uiadapter.o: uiadapter.c uiadapter.h quantity_ui.h presenter.h subject.h ioadapter.h
presenter.o: presenter.c presenter.h quantity_ui.h quantity.h
quantity_ui.o: quantity_ui.c quantity_ui.h
quantity.o: quantity.c quantity.h subject.h
main.o: main.c uiadapter.h ioadapter.h iotxtfile.h
iotxtfile.o: iotxtfile.c iotxtfile.h
ioadapter.o: ioadapter.c ioadapter.h observer.h
subject.o: subject.c subject.h observer.h
observer.o: observer.c observer.h

.PHONY: clean
clean:
	rm -f *.o main
