CC=gcc
CFLAGS = -Wall -g
all: Sort

Sort: main.o Sorting.o
	$(CC) $(CFLAGS) main.o Sorting.o -o Sort

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm a.out *.o Sort