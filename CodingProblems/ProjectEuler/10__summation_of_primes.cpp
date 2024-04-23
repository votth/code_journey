/*
 * The sum of the primes below 10 is:
 *		2 + 3 +5 +7 = 17
 *
 * Find the sum of all the primes below two million.
 */

#include <iostream>
#include <cmath>
// for setprecision()
#include <iomanip>
// for max_precision
#include <limits>
#include <numbers>

int main(void) {
	long double sum{2};
	bool flag{};
	const int limit = 2000000;
	constexpr auto max_precision {std::numeric_limits<long double>::digits10 + 1}; 

	for (int num = 3; num < limit; num += 2) {
		flag = true;
		for (int check = 3; check <= sqrt(num); ++check) {
			if (num % check == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			sum += num;
		}
	}

	std::cout << "Result: " << std::setprecision(max_precision) << sum << "\n";

	return 0;
}
