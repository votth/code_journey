#include <cs50.h>
#include <stdio.h>
#include <math.h>

// check if number falls under any of the 3 card categories
bool visa(long number);
bool amex(long number);
bool mc(long number);
// check if the number is legitimate
bool checksum(long number);
// helps with extracting digits for checksum()
short extractedDigit(long number, short i);

int main(void)
{
    long number = get_long("Enter credit card number (digit only): ");

    // greedily checking, if any of the ifs matches, then the program stops
    if (visa(number))
    {
        printf("VISA\n");
        return 0;
    }
    if (amex(number))
    {
        printf("AMEX\n");
        return 0;
    }
    if (mc(number))
    {
        printf("MASTERCARD\n");
        return 0;
    }

    // else it's invalid
    printf("INVALID\n");
    return 0;
}

bool visa(long number)
{
// check if 13 or 16 digits, and has a starting of 4
    if (floor(number / pow(10, 12)) == 4 || floor(number / pow(10, 15)) == 4)
    {
        // if checksum is valid then 'true' is returned
        return checksum(number);
    }
// if the number does not met the if condition, exit function with false
    return false;
}

bool amex(long number)
{
// check if 15 digits and starting of either 34 or 37
    if (floor(number / pow(10, 13)) == 34 || floor(number / pow(10, 13)) == 37)
    {
        // if checksum is valid then 'true' is returned
        return checksum(number);
    }
// if the number does not met the if condition, exit function with false
    return false;
}

bool mc(long number)
{
// check if 16 digits and starting in range of 51-55
    if (floor(number / pow(10, 14)) >= 51 && floor(number / pow(10, 14)) <= 55)
    {
        // if checksum is valid then 'true' is returned
        return checksum(number);
    }
// if the number does not met the if condition, exit function with false
    return false;
}

bool checksum(long number)
{
// result from Luhn's algo first step
    short product;
    short i, sum = 0;

// Step 1: looping through 'even' digits, couting from right-side
    for (i = 1; i <= 16; i += 2)
    {
        product = extractedDigit(number, i) * 2;
        if (product < 10)
        {
            sum += product;
        }
        else
        {
            sum += product + 1 - 10;
        }
    }

// Step 2: add the 'odd' digits to the sum
    for (i = 0; i <= 16; i += 2)
    {
        sum += extractedDigit(number, i);
    }

// Step 3: check if sum is a product of 10
    if (sum % 10 == 0)
    {
        return true;
    }
    return false;
}

short extractedDigit(long number, short i)
{
// cut off any digits that are 'after' the wanted digit
    long digitToLast = floor(number / pow(10, i));
// cut off until just before the wanted digit, then 'add' a 0 in its place
    long digitCut = floor(number / pow(10, i + 1)) * 10;

    return digitToLast - digitCut;
}