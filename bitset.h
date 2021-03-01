/**
 *@brief Implementation of bitset, project 1 - IJC.
 *@file bitset.h
 *@author Adam Zvara - xzvara01
 *@date 27.2.2021
 *@details Compiled with gcc 9.3
 */

typedef unsigned long* bitset_t;
typedef unsigned long bitset_index_t;

/// @todo Add comments to these too!
#define SIZE_ERROR "Velkost pola musi byt vacsia ako 0"
#define MALLOC_ERROR "bitset_alloc: Chyba alokace pameti"

#define ITEM_SIZE (sizeof(unsigned long)*CHAR_BIT)

/**
 * @brief Initialize bitset, first value is set to the size of bitset in bits.
 * @param name Name of a new bitset.
 * @param size Size of bitset in bits.
 * @todo Improve creating smaller bitset, if size == 32*k
 */
#define bitset_create(name, size)\
    _Static_assert((size > 0), SIZE_ERROR);\
    unsigned long name[size/ITEM_SIZE+2] = {size};

/**
 * @brief Initialize bitset dynamically, first value is set to the size of bitset in bits.
 * @param name Name of a new bitset.
 * @param size Size of bitset in bits. 
 * @todo Revisit checking if calloc was called succesfully
 * @todo Check max size possible
 */
#define bitset_alloc(name, size)\
    _Static_assert((size > 0), SIZE_ERROR);\
    unsigned long *name = calloc(size/ITEM_SIZE+2, sizeof(unsigned long));\
    name[0] = size;
    //((name == NULL) ? printf(MALLOC_ERROR) : (void) 0);

/**
 * @brief Frees previously allocated bitset.
 * @param name Name of the bitset.
 * @todo Figure out any ways to broke this  
 */
#define bitset_free(name) free(name);

/**
 * @brief Returns size of bitset in bits.
 * @param name Name of bitset.
 */
#define bitset_size(name) name[0]

/**
 * @brief Set single bit to a value at a given index.
 * @param name Name of the bitset.
 * @param index Index of the bit.
 * @param value Value to insert - 0 or 1
 */ 
#define bitset_setbit(name, index, value)\
    ((value != 0) ? (name[index/ITEM_SIZE+1] |= 1L << (index%ITEM_SIZE))\
                  : (name[index/ITEM_SIZE+1] &= ~(1L << (index%ITEM_SIZE))))

/**
 * @brief Get value from a bit at given index.
 * @param name Name of the bitset.
 * @param index Index of source bit.
 */
#define bitset_getbit(name, index)\
    ((name[index/ITEM_SIZE+1] >> (index%ITEM_SIZE)) & 1L)
