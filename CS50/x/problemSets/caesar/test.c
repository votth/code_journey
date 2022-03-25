#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    int key = 1;
    string ciphertext = "abcdef";

    printf("shift by 1 character\n");

    for(int i = 0; i < strlen(argv[1]); i++)
    {
        printf("%c\n\n", argv[1][i]);

        ciphertext[i] = argv[1][i] + key;

        printf("%c\n\n", ciphertext[i]);
    }

    printf("cipher: %s\n", ciphertext);

}