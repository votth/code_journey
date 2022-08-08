// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t *ptr_header = malloc(HEADER_SIZE);
    // !  uint8_t *ptr_header = malloc(sizeof(uint8_t) * HEADER_SIZE);
    //      this is same as the above
    // !! uint8_t *ptr_header = malloc(sizeof(HEADER_SIZE) * HEADER_SIZE);
    //      wasted memory and using it wrong

    // read/write to/from ptr_header, an amount of HEADER_SIZE * 1 (bytes) from/to input/output
    fread(ptr_header, HEADER_SIZE, 1, input);
    fwrite(ptr_header, HEADER_SIZE, 1, output);
    // using sizeof(HEADER_SIZE) here instead of HEADER_SIZE is wrong, since that will return '4' (bytes) of int instead of '44'
    // essentially, <qty> is counted in bytes already

    // give back the allocated/borrowed memory space
    free(ptr_header);

    // TODO: Read samples from input file and write updated data to output file
    int16_t *ptr_sample = malloc(sizeof(int16_t));
    // since here sample is a 2-byte size data, int16_t is 2-byte data type

    // while fread() hasn't reached EOF, I'm guessing EOF ~ 0
    while (fread(ptr_sample, sizeof(int16_t), 1, input))
    {
        // change the volume
        *ptr_sample *= factor;
        fwrite(ptr_sample, sizeof(int16_t), 1, output);
    }

    free(ptr_sample);

    // Close files
    fclose(input);
    fclose(output);
}
