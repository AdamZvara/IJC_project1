CC=gcc
CFLAGS=-m32 -std=C11 -Wall -Wextra -pedantic

test: bitset.c bitset.h
	$(CC) $^ -o $@
