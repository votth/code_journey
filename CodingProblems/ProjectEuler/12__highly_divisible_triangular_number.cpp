/*
 * The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1+2+3+4+5+6+7=28. The first ten terms would be:
 *		1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 * What is the value of the first triangle number to have over five hundred divisors?
 */

#include <iostream>

int main(void) {
	long triangle{};
	long tmp{};

	int divisor{};
	int counter{};
	int divSum{};

	for (int number = 1; 1; ++number) {
		triangle += number;
		// reset each loop
		tmp = triangle;
		divisor = 2;
		divSum = 1;

		// Find triangle's prime factors
		while (tmp != 1) {
			counter = 0;
			while (tmp % divisor == 0) {
				tmp /= divisor;
				++counter;
			}
			// calculate sum of divisors
			divSum *= counter + 1;
			++divisor;
		}

		if (divSum > 500) break;
	}

	std::cout << "Result: " << triangle << ", with " << divSum << " divisors.\n";

	return 0;
}
