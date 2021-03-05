#include "bitset.h"

extern inline void bitset_free(bitset_t name);
extern inline unsigned long bitset_size(bitset_t name);
extern inline void bitset_setbit(bitset_t name, bitset_index_t index, int value);
extern inline unsigned long bitset_getbit(bitset_t name, bitset_index_t index);

