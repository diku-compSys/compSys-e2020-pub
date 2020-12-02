CC = gcc
CFLAGS =-Wall -Wextra -pedantic -std=gnu11
LD_FLAGS = -lpthread

all : echoclient echoserveri echoserverp echoservert

rebuild : clean all

csapp.o : csapp.c csapp.h
	$(CC) $(CFLAGS) -c $< -o $@

echoclient : echoclient.c csapp.o
	$(CC) $(CFLAGS) $< *.o -o $@ $(LD_FLAGS)

echoserveri : echoserveri.c echo.c csapp.o
	$(CC) $(CFLAGS) $< echo.c *.o -o $@ $(LD_FLAGS)

echoserverp : echoserverp.c echo.c csapp.o
	$(CC) $(CFLAGS) $< echo.c *.o -o $@ $(LD_FLAGS)

echoservert : echoservert.c echo.c csapp.o
	$(CC) $(CFLAGS) $< echo.c *.o -o $@ $(LD_FLAGS)

clean :
	rm -rf *.o echoclient echoserveri echoserverp echoservert
