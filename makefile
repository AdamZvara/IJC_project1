CC=gcc
CFLAGS=-O2 -g -std=c11 -Wall -Wextra -pedantic

src=eratosthenes.h bitset.h error.h

all: primes primes-i clean

primes: primes.o eratosthenes.o error.o
	$(CC) $(CFLAGS) $^ -lm -o $@

primes.o: primes.c $(src)
	$(CC) $(CFLAGS) -c $<  

eratosthenes.o: eratosthenes.c $(src)
	$(CC) $(CFLAGS) -c $< 

primes-i: primes-i.o eratosthenes-i.o bitset.o error.o
	$(CC) $(CFLAGS) -DUSE_INLINE $^ -lm -o $@

primes-i.o: primes.c $(src)
	$(CC) $(CFLAGS) -DUSE_INLINE -c $< -o $@
 
eratosthenes-i.o: eratosthenes.c $(src)
	$(CC) $(CFLAGS) -DUSE_INLINE -c $< -o $@

bitset.o: bitset.c
	$(CC) $(CFLAGS) -DUSE_INLINE -c $< 

error.o: error.c error.h
	$(CC) $(CFLAGS) -c $<

run: 
	make all
	ulimit -s 25000; ./primes
	ulimit -s 25000; ./primes-i
clean:
	rm -f primes.o eratosthenes.o
	rm -f primes-i.o eratosthenes-i.o bitset.o
