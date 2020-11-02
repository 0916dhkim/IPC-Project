CC=gcc
CFLAGS=-I. -Wall -Werror
OBJ = a1ms4.o contacts.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

as1: $(OBJ)
	$(CC) $(OBJ) -o as1

.PHONY: clean

clean:
	rm *.o as1

