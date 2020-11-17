gcc=gcc -g -Werror -Wpedantic -Wall -pthread -o
# csapp=../csapp.c ../csapp.h

all: fstatcheck cpfile

fstatcheck: fstatcheck.c csapp.c csapp.h
	$(gcc) fstatcheck fstatcheck.c csapp.c

cpfile: cpfile.c csapp.c csapp.h
	$(gcc) cpfile cpfile.c csapp.c # $(csapp)

clean: 
	rm -f cpfile fstatcheck
