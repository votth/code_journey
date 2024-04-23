/*
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which:
 *		pow(a, 2) + pow(b, 2) = pow(c, 2)
 * 
 * For example, 3 - 4 - 5
 *
 * There exists exactly one Pythagorean triple for which:
 *		a + b + c = 1000
 *
 *	Find a*b*c
 */

#include <iostream>
#include <cmath>

int main(void) {
	/*
	 * (a + b)2 = c2 + 2ab
	 * (1000 - c)2 = c2 + 2ab
	 * 1000^2 - 2000c = 2ab
	 * 1000000c - 2000c^2 = 2abc
	 * 500000c - 1000c^2 = abc
	 */

	/*
	 * 1000c(500 - c) = abc
	 * 0 < c < 500
	 */

	/*
	 * 500 < a + b < 1000
	 */

	int a{}, b{}, c{};

	for (c = 1;c < 500; ++c) {
		for (b = 1; b < c; ++b) {
			for (a = 1; a < b; ++a) {
				if ( ((a + b + c) == 1000) && (pow(a, 2) + pow(b, 2) == pow(c, 2)) ) {
					std::cout << a << ", " << b << ", " << c << "\n";
					std::cout << "Result: " << a*b*c << "\n";
					return 0;
				}
			}
		}
	}

	std::cout << "Solution not found!\n";
	return 1;
}
