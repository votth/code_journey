#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t BYTE;

const int JPEG_BLOCK = 512;
// JPEG first 3 bytes: 0xff 0xd8 0xff
const BYTE FTHREE[] = {0xff, 0xd8, 0xff};

// returns 1 if first 4 bytes are valid, else 0
int firstFour(BYTE *byte);
// write out to ###.jpg recursively
void writeJPG(BYTE *byte, FILE *input, int count);

int main(int argc, char *argv[])
{
    // check if exactly 1 cli-argument
    if (argc != 2)
    {
        printf("Usage ./recover.c IMAGE\n");
        return 1;
    }
    // check if can open file
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Can't open file \"%s\".\n", argv[1]);
        return 1;
    }

    // assign buffer that can store 512B
    BYTE *byte = malloc(JPEG_BLOCK);

    // keep track of # of JPEG
    int count = 0;

    // search for the first JPEG
    while (fread(byte, 1, JPEG_BLOCK, input) == JPEG_BLOCK)
    {
        // check the first 4 bytes, if true, call writeJPG
        if (firstFour(byte))
        {
            writeJPG(byte, input, count);
        }
    }

    // free allocated memory and close file before exit
    free(byte);
    fclose(input);
    return 0;
}

// returns 1 if first 4 bytes are valid, else 0
int firstFour(BYTE *byte)
{
    int i;

    // check block first 3 bytes
    for (i = 0; i < 3; i++)
    {
        if (FTHREE[i] != byte[i])
        {
            return 0;
        }
    }
    // check if 4th block is a variance of '0xe0'
    if ((byte[3] & 0xf0) != 0xe0)
    {
        return 0;
    }
    // return 1 if this block is JPEG
    return 1;
}

// write out to ###.jpg recursively
void writeJPG(BYTE *byte, FILE *input, int count)
{
    // create file to write to with pre-formatted name
    // !! strlen() + 1
    char *filename = malloc(strlen("000.jpg") + 1);
    sprintf(filename, "%03i.jpg", count);
    // open to write
    FILE *output = fopen(filename, "w");

    do
    {
        // keep writing to the current file
        // and imediately read next block
        fwrite(byte, 1, JPEG_BLOCK, output);
        fread(byte, 1, JPEG_BLOCK, input);

        // if next block is a new start of the next JPEG
        // increase count and call this function (recursive)
        if (firstFour(byte))
        {
            count++;
            writeJPG(byte, input, count);
        }
    }
    while (!feof(input));

    // free allocated memory and close file before exit
    free(filename);
    fclose(output);

    return;
}