#include <stdio.h>
#include "eratosthenes.h"

#define len(name) printf("%u\n", sizeof(name)/sizeof(unsigned long))
//#define calloc(...) NULL

bitset_create(global, 128);

int main(void)
{
    bitset_create(ceil, 3200L);
    printf("lokalne makra:\n");
    len(global);
    bitset_create(exactly, 25);
    len(exactly);
    len(ceil);
    static bitset_create(statbset, 20);
    len(statbset);

    //generate compiler error
    //bitset_create(wrong, -100);
    
    printf("dynamicke makra:\n");

    bitset_alloc(bset_alloc, -1);
    bitset_setbit(bset_alloc, 127, 1);
    bitset_alloc(aset_alloc, 100);
    bitset_setbit(aset_alloc, 99, 1);
    //bitset_alloc(wrong, 2000000000);
    //bitset_alloc(wrong, -5);
    //
    
    printf("%lu", bitset_size(bset_alloc));

    bitset_free(bset_alloc);
    bitset_free(aset_alloc);
    
    //bitset_setbit(exactly, 30, 0);
    bitset_getbit(ceil, 3500);
    return 0;
}


