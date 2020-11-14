CC=gcc
CFLAGS=-I. -Wall -Werror
OBJ = contactHelpers.o contacts.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

as2: $(OBJ)
	$(CC) $(OBJ) -o as1

.PHONY: clean

clean:
	rm *.o as2

