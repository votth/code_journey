#include "helpers.h"
#include <math.h>
#include <stdio.h>

int Sobel_algo(int height, int width, RGBTRIPLE image[height][width], int color, int cR, int cC);
void copyImage(int height, int width, RGBTRIPLE input[height][width], RGBTRIPLE output[height][width]);

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
    // copy[][].R/G/B got normalized when going over 255 by default(?): doesn't save 300 as 300 but as 46 (300 - 254 (not 255 since counting 0))
    RGBTRIPLE copy[height][width];
    // needed to create another 3 variables
    int sRed, sGreen, sBlue;

    // cR and cC stand for current row, current column of the pixel
    int cR, cC;
    // count for how many neighboring pixels
    // float type for a more accurate result in division
    float neighbors;
    // index for looping
    int i, j;

    // blur_box calculation
    for (cR = 0; cR < height; cR++)
    {
        for (cC = 0; cC < width; cC++)
        {
            // reset
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

                    neighbors++;

                }
            }
            // set newColor to copy[][]
            copy[cR][cC].rgbtRed = round(sRed / neighbors);
            copy[cR][cC].rgbtGreen = round(sGreen / neighbors);
            copy[cR][cC].rgbtBlue = round(sBlue / neighbors);
        }
    }

    // parsing copy[][] to image[][]
    copyImage(height, width, copy, image);

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    // looping through pixels
    // cR and cC stand for current row, current column of the pixel
    for (int cR = 0; cR < height; cR++)
    {
        for (int cC = 0; cC < width; cC++)
        {
            // assigning new pixel value to copy[][].RGB
            copy[cR][cC].rgbtRed = Sobel_algo(height, width, image, 0, cR, cC);
            copy[cR][cC].rgbtGreen = Sobel_algo(height, width, image, 1, cR, cC);
            copy[cR][cC].rgbtBlue = Sobel_algo(height, width, image, 2, cR, cC);
        }
    }

    // parsing copy[][] to image[][]
    copyImage(height, width, copy, image);

    return;
}
// Calculating Gx, Gy and newColor for copy[][].RGB
int Sobel_algo(int height, int width, RGBTRIPLE image[height][width], int color, int cR, int cC)
{
    // color 0 1 2 for R G B
    // cR and cC = current row, current column
    // i, j for looping
    int i, j;
    // create "matrix" / 2 dimensional arrays Gx and Gy
    int Gx[3][3] =
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int Gy[3][3] =
    {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };
    // for storing Gx, Gy of RGB
    // x, y are rows 0 1, while R G B are columns 0 1 2 respectively
    int Gxy[2][3];
    // reset Gxy's table
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            Gxy[i][j] = 0;
        }
    }

    int newColor;

    // shifting above-current-below row loop
    for (i = - 1; i < 2; i++)
    {
        // if index is out-of-bound, skip
        if (cR + i < 0 || cR + i > height - 1)
        {
            continue;
        }

        // shifting left-current-right colum loop
        for (j = - 1; j < 2; j++)
        {
            // if index is out-of-bound, skip
            if (cC + j < 0 || cC + j > width - 1)
            {
                continue;
            }

            // Gx, Gy calculation
            // (i + 1 - cR) or (j + 1 - cC) essentially makes it so
            // [cR][cC] pixel aligns with Gx/y's [0][0] position
            switch (color)
            {
                case 0:
                    Gxy[0][color] += image[cR + i][cC + j].rgbtRed * Gx[i + 1][j + 1];
                    Gxy[1][color] += image[cR + i][cC + j].rgbtRed * Gy[i + 1][j + 1];
                    break;
                case 1:
                    Gxy[0][color] += image[cR + i][cC + j].rgbtGreen * Gx[i + 1][j + 1];
                    Gxy[1][color] += image[cR + i][cC + j].rgbtGreen * Gy[i + 1][j + 1];
                    break;
                case 2:
                    Gxy[0][color] += image[cR + i][cC + j].rgbtBlue * Gx[i + 1][j + 1];
                    Gxy[1][color] += image[cR + i][cC + j].rgbtBlue * Gy[i + 1][j + 1];
                    break;

                default:
                    break;
            }
        }
    }
    newColor = round(sqrt(Gxy[0][color] * Gxy[0][color] + Gxy[1][color] * Gxy[1][color]));

    return newColor > 255 ? 255 : newColor;
}

// parsing input[][] to output[][]
void copyImage(int height, int width, RGBTRIPLE input[height][width], RGBTRIPLE output[height][width])
{
    for (int cR = 0; cR < height; cR++)
    {
        for (int cC = 0; cC < width; cC++)
        {
            output[cR][cC] = input[cR][cC];
        }
    }
    return;
}