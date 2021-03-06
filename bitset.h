/**
 * @brief Implementation of bitset, task A) - IJC-DU1.
 * @file bitset.h
 * @author Adam Zvara - xzvara01, FIT
 * @date 6.3.2021
 * @details Compiled with gcc 9.3.0 - Ubuntu 20.04.1 
 */
    
#ifndef BITSET_H
#define BITSET_H

#include <stdlib.h>
#include <limits.h>
#include "error.h"

typedef unsigned long* bitset_t;
typedef unsigned long bitset_index_t;

#define ITEM_SIZE (sizeof(unsigned long)*CHAR_BIT) //</Size of a single item in bitset
#define MAX_LEN 200000000 //</Maximum range of bitset

#define SIZE_ERROR "Velkost pola musi byt v rozmedzi <0,200000000>"

/**
 * @brief Initialize bitset, first value is set to the size of bitset in bits.
 * @param name Name of a new bitset.
 * @param size Size of bitset in bits.
 * @todo Improve creating smaller bitset, if size == 32*k
 * @detail Creating bitset where size = 0 is possible. 
 */
#define bitset_create(name, size)\
    _Static_assert((size >= 0), SIZE_ERROR);\
    unsigned long name[size/ITEM_SIZE+2] = {size}

/**
 * @brief Initialize bitset dynamically, first value is set to the size of bitset in bits.
 * @param name Name of a new bitset.
 * @param size Size of bitset in bits. 
 * @detail Creating bitset where size = 0 is possible. 
 */
#define bitset_alloc(name, size)\
    _Static_assert((size >= 0), SIZE_ERROR);\
    _Static_assert((size <= MAX_LEN), SIZE_ERROR);\
    unsigned long *name = calloc(size/ITEM_SIZE+2, sizeof(unsigned long));\
    ((name == 0) ? (error_exit("bitset_alloc: Chyba alokace pameti\n"),0) : (name[0] = size))
    
/**
 * @brief Set a single bit in bitset to a given value.
 * @param name Bitset name.
 * @param index Index of the bit to change.
 * @param value Binary value to insert.
 */ 
#define setbit(name, index, value)\
    ((value != 0) ? (name[index/ITEM_SIZE+1] |= 1L << (index%ITEM_SIZE))\
                  : (name[index/ITEM_SIZE+1] &= ~(1L << (index%ITEM_SIZE))))

/**
 * @brief Get a single bit value from bitset at given index.
 * @param name Bitset name.
 * @param index Index of the source bit.
 */ 
#define getbit(name, index)\
    ((name[index/ITEM_SIZE+1] >> (index%ITEM_SIZE)) & 1L)



//Inline functions are similiar to macros defined underneath them.
#ifdef USE_INLINE

    inline void bitset_free(bitset_t name)
    {
        free(name);
    }

    inline unsigned long bitset_size(bitset_t name)
    {
        return name[0];
    } 

    inline void bitset_setbit(bitset_t name, bitset_index_t index, int value)
    { 
        if (index >= bitset_size(name))
        {
            error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", \
             (unsigned long)index, (unsigned long)bitset_size(name)-1);
        } 
        else 
        {
            setbit(name, index, value); 
        }
    }

    
    inline unsigned long bitset_getbit(bitset_t name, bitset_index_t index)
    {
        if (index >= bitset_size(name))
        {
            error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", \
             (unsigned long)index, (unsigned long)bitset_size(name)-1);
            return -1;
        } 
        else 
        {
            return (getbit(name, index)); 
        }
    }

#else
    /**
     * @brief Frees previously allocated bitset.
     * @param name Name of the bitset.
     */
    #define bitset_free(name) free(name)
    
    /**
     * @brief Returns size of bitset in bits.
     * @param name Name of bitset.
     */
    #define bitset_size(name) name[0]
    
    /**
     * @brief Improved setbit macro with boundary values detection.
     * @param name Name of the bitset.
     * @param index Index of the bit.
     * @param value Binary value to insert.
     */ 
    #define bitset_setbit(name, index, value)\
        ((index >= bitset_size(name)) ? \
         (error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", \
             (unsigned long)index, (unsigned long)bitset_size(name)-1), 0) : \
         (setbit(name, index, value)))
    
    /**
     * @brief Improved getbit macro with boundary values detection.
     * @param name Name of the bitset.
     * @param index Index of source bit.
     */
    #define bitset_getbit(name, index)\
        ((index >= bitset_size(name)) ? \
         (error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", \
             (unsigned long)index, (unsigned long)bitset_size(name)-1), 0) : \
         (getbit(name, index)))
#endif

#endif
