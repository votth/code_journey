#include <stdio.h>

int search(int* nums, int numsSize, int target);

int main(void)
{
	int nums[] = {-2, -1, 0, 3, 5, 9, 12};
	int numsSize = 7;
	int target = 9;

	int found_index = search(nums, numsSize, target);
	if  (found_index == -1)
	{
		printf("Not found\n");
	}
	else
	{
		printf("Found at position: %i\n", found_index);
	}

	return 0;
}

int search(int* nums, int numsSize, int target)
{
	int pivot, left = 0, right = numsSize - 1;
	while (left <= right)
	{
		pivot = left + (right - left) / 2;
		if (nums[pivot] == target) return pivot;
		if (target < nums[pivot]) right = pivot - 1;
		else left = pivot + 1;
	}
	return -1;
}
