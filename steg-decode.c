/**
 * @brief Decoding ppm image, task B) - IJC-DU1
 * @file steg-decode.c
 * @author Adam Zvara - xzvara01, FIT
 * @date 7.3.2021
 * @details Compiled with GCC
 */

#include "ppm.h"
#include "eratosthenes.h"

#define MAX_IMAGE_SIZE 8000*8000*3
#define START 23

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        error_exit("Nespravny pocet argumentov\n");
    }
    
    struct ppm *image = ppm_read(argv[1]);

    if (image == NULL)
    {
        error_exit("Subor sa nepodarilo precitat\n");
    }

    const long size = (image->xsize)*(image->ysize)*3;
    if (size > MAX_IMAGE_SIZE)
    {
        ppm_free(image);
        error_exit("Obrazok ma prilis velke rozmery\n");
    }

    bitset_alloc(bset, size);

    Eratosthenes(bset);

    unsigned int counter = 0;
    int character = 0;
    for (bitset_index_t i = START; i < bitset_size(bset); i++)
    {
        if (bitset_getbit(bset, i) == 0)
        {
            if ((image->data[i] & 1) == 1)
            {
                character |= (1 << counter);
            }
            
            if (counter == 7)
            {
                putchar(character);
                if (character == '\0') break;
                else 
                {
                    counter = 0;
                    character = 0;
                    continue;
                }
            }
            counter++;
        }
    }
    
    bitset_free(bset);
    ppm_free(image);
    return 0;
}
