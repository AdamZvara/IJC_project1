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

#define START 23
#define MESSAGE_LENGTH 100

void free_all(struct ppm* image, bitset_t bset, char * message)
{
    bitset_free(bset);
    ppm_free(image);
    free(message);
}

void message_resize(char *msg_name, const unsigned int size, struct ppm *image, bitset_t bset)
{
    void *new_name = realloc(msg_name, size);

    if (new_name == NULL)
    {
        free_all(image, bset, msg_name);
        error_exit("Realokacia spravy neprebehla spravne\n");
    }

    msg_name = new_name;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        error_exit("Nespravny pocet argumentov\n");
    }
    
    struct ppm *image = ppm_read(argv[1]);

    if (image == NULL) return 1;

    const long size = (image->xsize)*(image->ysize)*3;

    //creating bitset with primes numbers
    bitset_alloc(bset, size);
    Eratosthenes(bset);

    unsigned int bit_counter = 0,
                 character = 0,
                 character_count = 0,
                 length = MESSAGE_LENGTH;

    bool end_bit = false;
        
    //allocating message
    char *message = malloc(length);
    if (message == NULL)
    {
        free_all(image, bset, message);
        error_exit("Chyba pri alokacii spravy");
    }
    
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
                    length += MESSAGE_LENGTH;
                    message_resize(message, length, image, bset);
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
        free_all(image, bset, message);
        error_exit("Sprava nebola spravne ukoncena\n");
    }
    else
    {
        printf("%s", message);
    }
    
    free_all(image, bset, message);
    return 0;
}
