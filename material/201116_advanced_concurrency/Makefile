CFLAGS=-O3 -pthread -Wall -Wextra -pedantic
CC=gcc
PROGS=fibs fibs-futures fibs-mt fibs-threadpool fibs-threadpool-spin main-one-cv-while main-two-cvs-if main-two-cvs-while main-two-cvs-while-extra-unlock

all: $(PROGS)

%: %.c
	$(CC) -o $@ $< $(CFLAGS)

clean:
	rm -f $(PROGS)
