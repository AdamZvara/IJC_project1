/**
 * @brief Printing last 10 prime numbers up to 200 milion, task A) - IJC-DU1
 * @file primes.c
 * @author Adam Zvara - xzvara01, FIT
 * @date 6.3.2021
 * @details Compiled with gcc 9.3.0 - Ubuntu 20.04.1 

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
