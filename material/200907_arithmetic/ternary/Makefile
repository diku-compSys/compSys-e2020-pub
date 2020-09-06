CC = gcc
CFLAGS =-Wall -Wextra -pedantic -std=gnu11

all : ternary.o

rebuild : clean all

ternary.o : bcd.c bcd.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf *.o
