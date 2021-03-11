CC=gcc
CFLAGS=-m32 -O2 -g -std=c11 -Wall -Wextra -pedantic
LDFLAGS=-lm

src=eratosthenes.o error.o

objects=primes.o eratosthenes.o error.o steg-decode.o ppm.o 

all: primes primes-i steg-decode 

$(objects): %.o: %.c

#primes with macros
primes: primes.o $(src) 
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

#primes with inline functions
primes-i: primes-i.o eratosthenes-i.o bitset.o error.o
	$(CC) $(CFLAGS) -DUSE_INLINE $^ $(LDFLAGS) -o $@

primes-i.o: primes.c $(src)
	$(CC) $(CFLAGS) -DUSE_INLINE -c $< -o $@
 
eratosthenes-i.o: eratosthenes.c eratosthenes.h bitset.h error.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c $< -o $@

#inline functions with -O0
bitset.o: bitset.c bitset.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c $< 

#decoding
steg-decode: steg-decode.o ppm.o $(src)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

#testing
check: test_bitset clean

test_bitset: bitset_h_test.o $(src)
	$(CC) $(CFLAGS) $^ -lm -o $@

bitset_h_test.o: bitset_h_test.c bitset.h
	$(CC) $(CFLAGS) -c $<
#ending testing

run: 
	make all
	ulimit -s 25000; ./primes
	ulimit -s 25000; ./primes-i

clean:
	rm *.o
