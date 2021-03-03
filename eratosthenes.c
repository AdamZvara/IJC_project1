/**
 * @brief Implementation of eratosthenes function 
 * @file eratosthenes.c
 * @author: Adam Zvara, xzvara01
 * @date 3.3.2021
 */

#include <math.h>
#include "eratosthenes.h"

void Eratosthenes(bitset_t bset)
{
    const unsigned long length = bitset_size(bset);

    bitset_setbit(bset, 0, 1);
    bitset_setbit(bset, 1, 1);

    for (bitset_index_t i = 2; i < sqrt(length); i++)
    {
        if (bitset_getbit(bset, i) == 0)
        {
            for (bitset_index_t j = 2*i; j < length; j+=i)
            {
                bitset_setbit(bset, j, 1);
            }
        }
    }
}
