#include <stdio.h>
/* #include <cs50.h> */

int collatz(int n);

int main(void)
{
/*
    if n is 1 stop
	otherwise if n is even, repeat this process on n/2
	otherwise if n is odd, repeat this process on 3n + 1
*/
    int n;

    printf("n: ");
    scanf("%i", &n);

    printf("It takes %i steps.\n", collatz(n));
}

int collatz(int n)
{
    if (n == 1)
    {
	return 0;
    }

    if (n % 2 == 0)
    {
	return 1 + collatz(n/2);
    }

    if (n % 2 != 0)
    {
	return 1 + collatz(3*n + 1);
    }
}
