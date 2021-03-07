/**
 * @brief Processing ppm image into structure.
 * @file ppm.c
 * @author Adam Zvara - xzvara01, FIT
 * @date 6.3.2021
 * @details Compiled with gcc 9.3.0 - Ubuntu 20.04.1 
 */


#include <ctype.h>
#include "ppm.h"

#define MAX_SIZE 8000

struct ppm * ppm_read(const char* filename)
{
    FILE *fr = fopen(filename, "r");

    if (!fr)
    {
        warning_msg("Subor sa nepodarilo otvorit\n");
        return NULL;
    }

    int xsize, ysize = 0;
    int w1 = 0; //checking if there is a single whitespace after "header"

    if ((fscanf(fr, "P6 %d %d 255%lc", &xsize, &ysize, &w1) != 3) || (isspace(w1) == 0))
    {
        warning_msg("Nepodporovany format\n");
        fclose(fr);
        return NULL;
    }
    
    if ((xsize <= 0) || (ysize <= 0))
    {
        warning_msg("Neplatna velkost obrazku\n");
        fclose(fr);
        return NULL;
    }
    
    struct ppm *image = malloc(sizeof(struct ppm)+xsize*ysize*3);
    if (image == NULL)
    {
        warning_msg("Alokacia struktury neprebehla spravne\n");
        fclose(fr);
        return NULL;
    }

    image->xsize = xsize;
    image->ysize = ysize;

    int c, i = 0;
    while ((c = fgetc(fr)) != EOF)
    {
        image->data[i++] = c;
    }

    fclose(fr);
    return image;

}

void ppm_free(struct ppm *p)
{
    free(p);
}
