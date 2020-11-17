gcc=gcc -I../../ -g -Werror -Wpedantic -Wall -pthread -o

all: fstatcheck cpfile cpfile_infile

fstatcheck: fstatcheck.c
	$(gcc) fstatcheck fstatcheck.c csapp.c

cpfile: cpfile.c
	$(gcc) cpfile cpfile.c csapp.c

cpfile_infile: cpfile_infile.c
	$(gcc) cpfile_infile cpfile_infile.c csapp.c


clean: 
	rm -f cpfile fstatcheck cpfile_infile
