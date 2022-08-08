#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // to avoid having to declear cents as int over and over
    int cents;
    do
    {
        cents = get_int("The amount of owned cents: ");
    }
    while (cents < 0);

    return cents;
}

int calculate_quarters(int cents)
{
    // Similar for all the functions below, since the functions are 'int', float result will just be int when 'return'ed
    if (cents >= 25)
    {
        return cents / 25;
    }
    return 0;

}

int calculate_dimes(int cents)
{
    // TODO
    if (cents >= 10)
    {
        return cents / 10;
    }
    return 0;
}

int calculate_nickels(int cents)
{
    // TODO
    if (cents >= 5)
    {
        return cents / 5;
    }
    return 0;
}

int calculate_pennies(int cents)
{
    // TODO
    if (cents >= 1)
    {
        return cents / 1;
    }
    return 0;
}
