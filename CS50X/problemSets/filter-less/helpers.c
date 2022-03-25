#include "helpers.h"
#include <math.h>
#include <stdio.h>

// returns to 255 if a color exceeds it
BYTE capColor(float color);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // new color value
    BYTE gray;

    // going through rows/height
    for (int i = 0; i < height; i++)
    {
        // going by columns/width
        for (int j = 0; j < width; j++)
        {
            // divide for 3.0 so that the result is considered as float for accuracy, then using round(result) to 'round' to nearest int
            gray = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            // set the gray color to the BGR
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtRed = gray;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // new color values
    float sBlue, sGreen, sRed;
    // why did declaring BYTE here wrong for the complex 3x3 and 4x4 checks??? weird interaction with round() of capColor()???

    // going through rows/height
    for (int i = 0; i < height; i++)
    {
        // going by columns/width
        for (int j = 0; j < width; j++)
        {
            // sepia calculations
            sBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            sGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);

            // parsing new color to image's pixel
            image[i][j].rgbtBlue = capColor(sBlue);
            image[i][j].rgbtGreen = capColor(sGreen);
            image[i][j].rgbtRed = capColor(sRed);
        }
    }

    return;
}
// check for 255 cap
BYTE capColor(float color)
{
    if (color > 255)
    {
        return 255;
    }
    return color;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE swap;

    // going by row
    for (int i = 0; i < height; i++)
    {
        // going from first to mid-point column
        for (int j = 0; j < width / 2; j++)
        {
            // flipping pixel by column
            swap = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = swap;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // copy[][].R/G/B got capped to 255, why?!?!?! if it goes over then it starts "counting" from 0, leading to wrong sum result
    RGBTRIPLE copy[height][width];
    // needed to create another 3 variables
    int sRed, sGreen, sBlue;

    // cR and cC stand for current row, current column of the pixel
    int cR, cC;
    // float type for a more accurate result in division
    // count for how many neighboring pixels
    float neighbors;
    // index for looping
    int i, j;

    // blur_box calculation
    // for (cR = height - 1; cR < height; cR++)
    // {
    //     for (cC = 0; cC < 1; cC++)
    //     {
    for (cR = 0; cR < height; cR++)
    {
        for (cC = 0; cC < width; cC++)
        {

            sRed = 0;
            sGreen = 0;
            sBlue = 0;
            neighbors = 0;

            // above-current-below row loop
            for (i = cR - 1; i <= cR + 1; i++)
            {
                // if index is out-of-bound, skip
                if (i < 0 || i > height - 1)
                {
                    continue;
                }

                // left-current-right colum loop
                for (j = cC - 1; j <= cC + 1; j++)
                {
                    // if index is out-of-bound, skip
                    if (j < 0 || j > width - 1)
                    {
                        continue;
                    }

                    sRed += image[i][j].rgbtRed;
                    sGreen += image[i][j].rgbtGreen;
                    sBlue += image[i][j].rgbtBlue;

                    // printf("aPixel: %i %i %i\n", image[i][j].rgbtRed, image[i][j].rgbtGreen, image[i][j].rgbtBlue);
                    // printf("cPixel: %i %i %i\n", sRed, sGreen, sBlue);

                    neighbors++;

                }
            }

            // // average out the value
            // printf("cPixel: %i %i %i\n", sRed, sGreen, sBlue);
            copy[cR][cC].rgbtRed = round(sRed / neighbors);
            copy[cR][cC].rgbtGreen = round(sGreen / neighbors);
            copy[cR][cC].rgbtBlue = round(sBlue / neighbors);

            // printf("bPixel: %i %i %i\n", copy[cR][cC].rgbtRed, copy[cR][cC].rgbtGreen, copy[cR][cC].rgbtBlue);
            // printf("%f\n\n", neighbors);
        }
    }

    // parsing copy[][] to image[][]
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }

    return;
}