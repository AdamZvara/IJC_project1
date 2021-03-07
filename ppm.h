/**
 * @brief Header file for ppm.c, task B) - IJC-DU1
 * @file ppm.h
 * @author Adam Zvara - xzvara01, FIT
 * @date 7.3.2021
 * @details Compiled with gcc 9.3.0 - Ubuntu 20.04.1 
 */

#include "error.h"

#ifndef PPM_H
#define PPM_H

/**
 * @struct ppm
 * @brief Structure (with flexible array) used to store data from PPM image format.
 * @var ppm::xsize
 * Member 'xsize' contains width of image (in pixels).
 * @var ppm::ysize
 * Member 'ysize' contains height of image (in pixels).
 * @var ppm::data
 * Member 'data' is flexible array used to store RGB byte values from image.
 */
struct ppm 
{
    unsigned xsize;
    unsigned ysize;
    char data[];
};

/**
 * @brief Extract data from file to structure ppm.
 * @param filename Name of the file with PPM format.
 * @return ppm* Pointer to a dynamically allocated structure.
 */
struct ppm * ppm_read(const char* filename);

/**
 * @brief Frees previously allocated ppm structure.
 * @param ppm Pointer to the structure to free.
 */
void ppm_free(struct ppm *p);

#endif
