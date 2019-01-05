CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDLIBS=-lncurses

main: main.o quantity.o quantity_ui.o uiadapter.o subject.o observer.o ioadapter.o iotxtfile.o

main.o: main.c quantity.h quantity_ui.h uiadapter.h ioadapter.h iotxtfile.h subject.h
quantity.o: quantity.c quantity.h subject.h
quantity_ui.o: quantity_ui.c quantity_ui.h quantity.h quantity.h observer.h
uiadapter.o: uiadapter.c uiadapter.h quantity.h quantity_ui.h subject.h
subject.o: subject.c subject.h observer.h
observer.o: observer.c observer.h
ioadapter.o: ioadapter.c ioadapter.h observer.h
iotxtfile.o: iotxtfile.c iotxtfile.h

.PHONY: clean
clean:
	rm -f *.o main
