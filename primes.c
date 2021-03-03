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
<<<<<<< HEAD
    int counter = AMOUNT-1;

    for (bitset_index_t i = N-1; i > 1; i--) //loop backwards
=======
    int counter = 0;

    for (bitset_index_t i = N; i > 1; i--) //loop backwards
>>>>>>> 902ba266b17ea5aae4d0e69cd54665c381717264
    {
        if (bitset_getbit(bset, i) == 0)
        {
            primes[counter] = i;
<<<<<<< HEAD
            counter--;
        }

        if (counter < 0)
=======
            counter++;
        }

        if (counter == AMOUNT)
>>>>>>> 902ba266b17ea5aae4d0e69cd54665c381717264
            break;
    }

    for (int i = 0; i < AMOUNT; i++)
    {
        printf("%lu\n", primes[i]);
    }

}
