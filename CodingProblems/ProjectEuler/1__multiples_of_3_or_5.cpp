/*
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
 * The sum of these mutiplier is 23.
 *
 * Find the sum of all the multipliers of 3 or 5 below 1,000.
 */

#include <iostream>

int main(void) {
	int sum{};

	for (int i = 1; i < 1000; ++i) {
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}

	std::cout << "Sum of all mutiples of 3 or 5 below 1000: " << sum << std::endl;
	
	return 0;
}
