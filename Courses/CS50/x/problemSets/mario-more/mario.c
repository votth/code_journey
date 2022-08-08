#include <cs50.h>
#include <stdio.h>

int main(void)
{
// pre-assign n for height, i and j for looping
    int n, i, j;

// make user retypes if n is out of range 1-8
    do
    {
        n = get_int("How tall should the pyramid be (1-8)? ");
    }
    while (n > 8 || n < 1);

// first loop is for going floor by floor from top down
    for (i = 1; i < n + 1; i++)
    {
        // i floor will have i number of hash, therefore n-i number of spaces are required
        for (j = 0; j < n - i; j++)
        {
            printf(" ");
        }
        for (j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (j = 0; j < i; j++)
        {
            printf("#");
        }
        // to actually go to next floor/line
        printf("\n");
    }
}
