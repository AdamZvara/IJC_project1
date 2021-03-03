#@todo rewrite makefile
CC=gcc
CFLAGS=-m32 -O2 -g -std=c11 -Wall -Wextra -pedantic -fsanitize=address

src=primes.c bitset.h eratosthenes.c eratosthenes.h

primes: $(src)
	$(CC) $(CFLAGS) $< eratosthenes.c -lm -o $@

