CC=gcc
CFLAGS=-I. -Wall -Werror
OBJ = contactHelpers.o contacts.o a2ms2.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

as2: $(OBJ)
	$(CC) $(OBJ) -o as2

.PHONY: clean

clean:
	rm *.o as2

