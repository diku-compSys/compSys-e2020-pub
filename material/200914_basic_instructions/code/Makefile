
CC = gcc
OFLAGS = -Og
CFLAGS = $(OFLAGS) -Wall -g
CINC =

.SUFFIXES: .c .s .o .d

%.s:%.c
	$(CC) $(OFLAGS) $(CINC) -S $(F64) $*.c -o $*.s

%.d:%.c
	$(CC) $(CFLAGS) $(CINC) $(F64) $*.c -o $*
	objdump -d $* > $*.d
	rm -f $*

files:	sum.s	sum.d	sum64 swap.s arith.s


sum: sum.c
	$(CC) $(CFLAGS) $(CINC) $(F64) sum.c -o sum64

clean:
	rm -f *~ *.s *.d sum
