CC=gcc
CFLAGS=-m32 -g -std=c11 -Wall -Wextra -pedantic -fsanitize=address

test: bitset.c bitset.h
	$(CC) $< -o $@ $(CFLAGS)

CFLAGS+=-lm
primes: eratosthenes.c
	$(CC) $< -o $@ $(CFLAGS)
