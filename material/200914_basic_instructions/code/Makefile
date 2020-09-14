
CC = gcc
OFLAGS = -Og
CFLAGS = $(OFLAGS) -Wall -g
CINC =

.SUFFIXES: .c .s .o .d

# Compile a C program to assembler. ".s" is the common file extension.
%.s:%.c
	$(CC) $(OFLAGS) $(CINC) -S $(F64) $*.c -o $*.s

# Generate a hex-dump from a C program
%.d:%.c
	$(CC) $(CFLAGS) $(CINC) $(F64) $*.c -o $*
	objdump -d $* > $*.d
	rm -f $*

# Compile the sum program
sum: sum.c
	$(CC) $(CFLAGS) $(CINC) $(F64) sum.c -o sum

# Clean up after yourself
clean:
	rm -f *~ *.s *.d sum *.hex *.prime *.sym
