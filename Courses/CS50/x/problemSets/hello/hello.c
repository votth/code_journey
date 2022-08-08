#include <cs50.h>
#include <stdio.h>

int main(void)
{
// Getting the user's name
    string name = get_string("Your name is: ");

// Printing out user's name with hello
    printf("hello, %s\n", name);
}