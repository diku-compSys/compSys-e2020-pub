# replace prime_dir with path to your own installation of x86prime
prime_dir = ~/x86prime

primify   = $(prime_dir)/primify
prasm     = $(prime_dir)/prasm
prun      = $(prime_dir)/prun

GCC = gcc -S -O3 -fno-optimize-sibling-calls 


all: a_sum.hex


a_sum.s: a_sum.c
	$(GCC) a_sum.c


a_sum.prime: a_sum.s
	$(primify) a_sum.s && rm -f a_sum.s


a_sum.hex: a_sum.prime
	$(prasm) a_sum.prime


run_a_sum: a_sum.hex
	$(prun) a_sum.hex plus -show



clean:
	rm -f *.s *.prime *.hex *.sym
