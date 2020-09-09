# OS X users should use additionally gcc-6, gcc will invoke the Clang compiler
CC=gcc-10
CFLAGS=-std=c11 -Wall -Werror -Wextra -pedantic
PROGRAMS=macro lastchar segfault
# LIBS=myio.c

.PHONY: clean all

all:
	make $(PROGRAMS)

macro: macro.c
	$(CC) $(CFLAGS) -g -o $@ $<

lastchar: lastchar.c
	$(CC) $(CFLAGS) -g -o $@ $<

segfault: segfault.c
	$(CC) $(CFLAGS) -g -o $@ $<

clean:
	rm -f $(PROGRAMS)
# Needed to clean OS X debug information}
	rm -fr $(foreach prg,$(PROGRAMS),$(prg).dSYM)
