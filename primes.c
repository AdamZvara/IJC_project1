/**
 * @brief Using eratosthenes sieve to calculate prime numbers.
 * @file primes.c
 * @author Adam Zvara, xzvara01
 * @date 3.3.2021
 */

#include <stdio.h>
#include "eratosthenes.h"
#include <time.h>

#define N 200000000 //</ Upper limit for prime numbers.
#define AMOUNT 10 //</ Number of prime numbers to store.

int main(void)
{
    clock_t begin = clock();

    bitset_create(bset, N);
    //bitset_alloc(bset, N);

    Eratosthenes(bset); // Creating bitset with prime numbers

    unsigned long primes[AMOUNT];
    int counter = AMOUNT-1;

    for (bitset_index_t i = N-1; i > 1; i--) //loop backwards
    {
        if (bitset_getbit(bset, i) == 0)
        {
            primes[counter] = i;
            counter--;
        }

        if (counter < 0)
            break;
    }

    for (int i = 0; i < AMOUNT; i++)
    {
        printf("%lu\n", primes[i]);
    }

    clock_t end = clock();
    fprintf(stderr, "Time=%.3g\n", (double)(end-begin)/CLOCKS_PER_SEC); 
}
