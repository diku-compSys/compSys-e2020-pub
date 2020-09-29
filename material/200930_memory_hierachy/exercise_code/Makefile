CC = gcc
CFLAGS = -O3 -Wall

all: cols rows

cols: sum-array-cols.c
	$(CC) $(CFLAGS) -o sum-array-cols sum-array-cols.c

rows: sum-array-rows.c
	$(CC) $(CFLAGS) -o sum-array-rows sum-array-rows.c

clean:
	rm -f rows cols


