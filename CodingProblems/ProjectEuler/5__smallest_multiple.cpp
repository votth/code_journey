/* 
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is 'evenly divisible' by all of the numbers from 1 to 20?
 */

#include <iostream>
#include <map>
#include <cmath>

int main(void) {
	const int RANGE = 20;

	std::map<int, int> factor{};
	int result{1};
	int tmp{};
	int counter{};

	for (int i = RANGE; i >= 2; --i) {
		tmp = i;
		for (int j = 2; j <= tmp; ++j) {
			counter = 0;
			while (tmp % j == 0) {
				tmp /= j;
				counter++;
			}
			if (counter > factor[j]) {
				factor[j] = counter;
			}
		}
	}

	for (const auto& i : factor) {
		result *= std::pow(i.first, i.second);
	}

	std::cout << result << "\n";

	return 0;
}
