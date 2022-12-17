#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        return 1;
    }

    BYTE buffer[512];
    int count = 0;
    FILE *restored_img = NULL;
    char filename[8];

    // Repeat to read 512 bytes to a buffer
    while (fread(&buffer, 512, 1, card))
    {
        // Check start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count)
            {
                fclose(restored_img);
            }

            // write Jpeg photo file
            sprintf(filename, "%03i.jpg", count);
            restored_img = fopen(filename, "w");
            count++;
        }

        // other Jpeg found
        if (count)
        {
            fwrite(&buffer, 512, 1, restored_img);
        }
    }

    fclose(card);
    fclose(restored_img);
    return 0;
}