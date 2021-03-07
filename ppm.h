/**
 * @brief Header file for ppm.c, task B) - IJC-DU1
 * @file ppm.h
 * @author Adam Zvara - xzvara01, FIT
 * @date 6.3.2021
 * @details Compiled with GCC
 */

#include <stdio.h>
#include <stdlib.h>
#include "error.h"

#ifndef PPM_H
#define PPM_H

struct ppm 
{
    unsigned xsize;
    unsigned ysize;
    char data[];
};

struct ppm * ppm_read(const char* filename);

void ppm_free(struct ppm *p);

#endif
