/**
 * @brief Using eratosthenes sieve to calculate prime numbers.
 * @file primes.c
 * @author Adam Zvara, xzvara01
 * @date 3.3.2021
 */

#include <stdio.h>
#include "eratosthenes.h"

#define N 200000000 //</ Upper limit for prime numbers.
#define AMOUNT 10 //</ Number of prime numbers to store.

int main(void)
{
    bitset_create(bset, N);
    
    Eratosthenes(bset); // Creating bitset with prime numbers

    unsigned long primes[AMOUNT];
    int counter = 0;

    for (bitset_index_t i = N; i > 1; i--) //loop backwards
    {
        if (bitset_getbit(bset, i) == 0)
        {
            primes[counter] = i;
            counter++;
        }

        if (counter == AMOUNT)
            break;
    }

    for (int i = 0; i < AMOUNT; i++)
    {
        printf("%lu\n", primes[i]);
    }

}
