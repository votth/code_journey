#include <stdio.h>
#include <string.h>

// initiate array of strings
char **arr[] = {"flower", "flow", "flight"};

int shortest_string_index();
void comparision(char *base, int shift);

int main(void)
{
	// find the shortest string in the array
	// that'll be the "base" for the 'longest common string' (LCS)
	int shortest = shortest_string_idex();
	// string copy arr[shortest] to base
	char *base = arr[shortest];

	// compare the temp LCS to part(s) of the other strings
	// if anything returns 'false', reduce the temp LCS's length
	// and repeat the comparision process
	comparision(base, 0);

	// if still receives 'false', return LCS as empty
	printf("The longest common string: <NULL>");
	return 1;
}

int shortest_string_index()
{
	int min = 0;
	int n = sizeof(arr);
	for (int i = 1; i < n; i++)
	{
		if (strlen(arr[i]) < strlen(arr[min]))
		{
			min = i;
		}
	}
	return min;
}

void comparision(char *base, int shift)
{
	bool found = true;
	char *lcs = malloc(strlen(base) + 1 - shift);

	for (int curr_shift = 0; curr_shift < shift + 1; curr_shift++)
	{	
		lcs = base[curr_shift];

		// 0 loop
		// comparing with the whole length of the shortest string
		for (int i = 0; i < sizeof(arr); i++)
		{
			if(strcmp(base, arr[i]))
			
			{
			}

			if(!strcmp(lcs, part_of(arr[i])))
			{
				found = false;
			}
		}

		if(!found)
		{
			shift++;
			comparision(lcs, shift);
		}
	}

	// 1 loop
	// reduce the LCS length by 1
	// comparing to "LCS missing tail char"
	// comparing to "LCS missing head char"

	// 2 loop
	// reduce the LCS length by 2
	// comparing to LCS missing 2-tail chars
	// comparing to LCS missing 1-head and 1-tail chars
	// comparing to LCS missing 2-head chars

	// stop when LCS is <NULL> or comparision all return 'found'
}
