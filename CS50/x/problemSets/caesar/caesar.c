#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string input);
char rotate(char plaintext, int key);

int main(int argc, string argv[])
{
// take input, enter at program's execution, only number and 1 number
// argv[1] is digit?
    if (argc != 2)
    {
        printf("Please run the program again with exactly 'one number'.\n");
        return 1;
    }
// checking if user input a number
    if (!only_digits(argv[1]))
    {
        printf("You need to run the program with a number.\n");
        return 1;
    }

// working with key as a number
// %26 for when key is bigger than 26, realistically we only loop Z back to A
// so any 'multiplication' of 26 is just unnecessary looping
    int key = atoi(argv[1]) % 26;
    int i = 0;

    string plaintext = get_string("plaintext:  ");

// cipher printing
    printf("ciphertext: ");
    while (plaintext[i] != '\0')
    {
        printf("%c", rotate(plaintext[i], key));

        i++;
    }
    printf("\n");

// END
}

bool only_digits(string input)
{
    int i = 0;

    while (input[i] != '\0')
    {
        if (input[i] < '0' || input[i] > '9')
        {
            return false;
        }

        i++;
    }

    return true;
}

char rotate(char plaintext, int key)
{
// although ciphertext var is not really needed, it's there for transparency
// initial value is for when plaintext is not letter
    char ciphertext = plaintext;

// if plaintext is letter
    if (('a' <= plaintext && plaintext <= 'z') || ('A' <= plaintext && plaintext <= 'Z'))
    {
        // if after 'rotation'/adding key cipher isn't a lowercase alphabet
        // or when plaintext starts out as UPPERCASE and cipher is not UPPERCASE
        // for example: if plaintext is 'Z' and key is 7, cipherr is 'a'
        if (plaintext + key > 'z' || (plaintext <= 'Z' && plaintext + key > 'Z'))
        {
            ciphertext = plaintext - 26 + key;
        }
        // else just rotate like normal, cipher = plain + key
        else
        {
            ciphertext = plaintext + key;
        }
    }

    return ciphertext;
}