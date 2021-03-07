CC=gcc
CFLAGS=-m32 -O2 -g -std=c11 -Wall -Wextra -pedantic

src=eratosthenes.h bitset.h error.h

all: primes primes-i steg-decode clean

#primes with macros
primes: primes.o eratosthenes.o error.o
	$(CC) $(CFLAGS) $^ -lm -o $@

primes.o: primes.c $(src)
	$(CC) $(CFLAGS) -c $<  

eratosthenes.o: eratosthenes.c $(src)
	$(CC) $(CFLAGS) -c $< 

#primes with inline functions
primes-i: primes-i.o eratosthenes-i.o bitset.o error.o
	$(CC) $(CFLAGS) -DUSE_INLINE $^ -lm -o $@

primes-i.o: primes.c $(src)
	$(CC) $(CFLAGS) -DUSE_INLINE -c $< -o $@
 
eratosthenes-i.o: eratosthenes.c $(src)
	$(CC) $(CFLAGS) -DUSE_INLINE -c $< -o $@

#inline functions with -O0
bitset.o: bitset.c
	$(CC) $(CFLAGS) -DUSE_INLINE -c $< 

error.o: error.c error.h
	$(CC) $(CFLAGS) -c $<

#decoding
steg-decode: steg-decode.o ppm.o error.o eratosthenes.o
	$(CC) $(CFLAGS) $^ -lm -o $@

steg-decode.o: steg-decode.c ppm.h eratosthenes.h
	$(CC) $(CFLAGS) -c $<

ppm.o: ppm.c ppm.h 
	$(CC) $(CFLAGS) -c $< 


run: 
	make all
	ulimit -s 25000; ./primes
	ulimit -s 25000; ./primes-i
	./steg-decode du1-obrazek.ppm
clean:
	rm *.o
