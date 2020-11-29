CC=gcc
CFLAGS=-I. -Wall -Werror
OBJ = contactHelpers.o contacts.o a2ms4.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

as4: $(OBJ)
	$(CC) $(OBJ) -o as4

.PHONY: clean

clean:
	rm *.o as4

