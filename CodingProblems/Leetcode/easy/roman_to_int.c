#include <stdio.h>
#include <string.h>

int romanToInt(char *s);

int main(void)
{
	char *s;
	printf("Input your roman number: ");
	scanf("%c", s);

	if (1 <= strlen(s) && strlen(s) <= 15)
	{
		printf("%i\n", romanToInt(s));
		return 0;
	}

	printf("The given roman number is too long.\n");
	return 1;
}

int romanToInt(char *s)
{
	char letters[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	int values[] = {1, 5, 10, 50, 100, 500, 1000};

	int sum = 0;

	for (int i = 0; i < strlen(s); i++)
	{
		for (int j = 0; j < sizeof(letters); j++)
		{
			if (s[i] == letters[j])
			{
				sum += values[j];
				break;
			}
		}
	}

	return sum;
}
