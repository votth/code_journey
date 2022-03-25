#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool unique_letters(string key);
char rotate(char plaintext, string key);

int main(int argc, string argv[])
{
// check if there's indeed only 1 input
    if (argc != 2)
    {
        printf("Please run the program again with a 26-letter key.\n");
        return 1;
    }
// check if the only input is indeed 26 characters
    if (strlen(argv[1]) != 26)
    {
        printf("You need to run the program with a 26-letter key.\n");
        return 1;
    }
// check if the input is only consisted of letters
    if (!unique_letters(argv[1]))
    {
        printf("Please use key with unique letters.\n");
        return 1;
    }

// i for looping
    int i = 0;
    string plaintext = get_string("plaintext:  ");

// cipher printing
    printf("ciphertext: ");
    while (plaintext[i] != '\0')
    {
        printf("%c", rotate(plaintext[i], argv[1]));

        i++;
    }
    printf("\n");

// END
}

bool unique_letters(string key)
{
    int i = 0;

    while (key[i] != '\0')
    {
        // if any characters is not alpha
        if (!isalpha(key[i]))
        {
            return false;
        }

        // checking if it's a unique character within the key
        for (int j = 0; j < i; j++)
        {
            if (key[i] == key[j])
            {
                printf("Duplicate characters in key is not allowed.\n");
                return false;
            }
        }

        i++;
    }

// if the program reaches here, meaning the key is valid
    return true;
}

char rotate(char plaintext, string key)
{
// initialize cipher
    char ciphertext = plaintext;

// check if the character is alpha
    if (isalpha(plaintext))
    {
        // check if the character is lowercase
        if (islower(plaintext))
        {
            // since key has 26 characters, and an array counting from 0
            // meaning cipher's A/a = key[0]
            // but plaintext's a is 97 (ASCII code), therefore minue 97 would get us the index for key's array
            ciphertext = tolower(key[(int)(plaintext - 97)]);
        }
        // since it's alpha and is not lowercase, meaning UPPERCASE
        else
        {
            ciphertext = toupper(key[(int)(plaintext - 65)]);
        }
    }

// if the if statement is false, plain is not alpha then just print out plaintext
    return ciphertext;
}