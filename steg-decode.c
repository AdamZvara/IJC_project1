/**
 * @brief Decoding ppm image, task B) - IJC-DU1
 * @file steg-decode.c
 * @author Adam Zvara - xzvara01, FIT
 * @date 7.3.2021
 * @details Compiled with GCC
 */

#include <stdbool.h>
#include "ppm.h"
#include "eratosthenes.h"

#define MAX_IMAGE_SIZE 8000*8000*3
#define START 23

void message_resize(char *name, unsigned int size)
{
    void *new_name = realloc(name, size);

    if (new_name == NULL)
    {
        if (name != NULL) free(name);
        error_exit("Alokacia spravy neprebehla spravne\n");
    }

    name = new_name;
}

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

    unsigned int bit_counter = 0;
    unsigned int character = 0;
    
    unsigned int length = 100;
    unsigned int character_count = 0;
    char *message = malloc(length);
    if (message == NULL)
    {
        ppm_free(image);
        error_exit("Chyba pri alokacii spravy");
    }
    bool end_bit = false;
    
    for (bitset_index_t i = START; i < bitset_size(bset); i++)
    {
        if (bitset_getbit(bset, i) == 0)
        {
            if ((image->data[i] & 1) == 1)
            {
                character |= (1 << bit_counter);
            }
            
            if (bit_counter == 7)
            {
                if (character_count / length)
                {
                    length += 100;
                    message_resize(message, length);
                }

                message[character_count++] = character;
                
                if (character == '\0') 
                {
                    end_bit = true;
                    break;   
                }
                else 
                {
                    bit_counter = 0;
                    character = 0;
                    continue;
                }
            }
            bit_counter++;
        }
    }

    if (end_bit == false)
    {
        free(message);
        ppm_free(image);
        error_exit("Sprava nebola spravne ukoncena\n");
    }
    else
    {
        printf("%s", message);
    }
    
    free(message);
    bitset_free(bset);
    ppm_free(image);
    return 0;
}
