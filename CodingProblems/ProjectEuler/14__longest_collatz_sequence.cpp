/*
 * The following iterative sequence is defined for the set of positive integers:
 *		n -> n/2 (n is even)
 *		n -> 3n+1 (n is odd)
 * Using the rule above and starting with 13, we generate the following sequence:
 *		13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), is is thought that all starting numbers finish at 1.
 *
 * Which starting number, under on million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowd to go above one million.
 */

#include <iostream>
#include <map>

int collatzSequenceLength(int32_t number, std::map<int32_t, int>& lengthM);

int main(void) {
	int32_t number{};
	int32_t result{};

	int length{};
	int maxLength{};
	std::map<int32_t, int> lengthM{};

	for (number = 1; number < 1000000; ++number) {
		length = collatzSequenceLength(number, lengthM);
		if (length > maxLength) {
			maxLength = length;
			result = number;
		}
	}

	std::cout << "Result: " << result << ", with " << maxLength << " steps.\n";

	return 0;
}

int collatzSequenceLength(int32_t number, std::map<int32_t, int>& lengthM) {
	int length{};

	if (number == 1) return 1;
	if ( lengthM.contains(number) ) return lengthM[number];
	if (number % 2 == 0) {
		length = 1 + collatzSequenceLength(number / 2, lengthM);
	} else {
		length = 1 + collatzSequenceLength(3*number + 1, lengthM);
	}

	lengthM[number] = length;
	return length;
}
