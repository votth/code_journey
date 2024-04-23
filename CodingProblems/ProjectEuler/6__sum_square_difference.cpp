/* 
 * The sum of squares vs the square of sum
 */

#include <iostream>
#include <cmath>

int main(void) {
	int separately{};
	int group{};

	for (int i = 1; i <= 100; ++i) {
		group += i;
		separately += std::pow(i, 2);
	}

	group = std::pow(group, 2);

	std::cout << separately - group << "\n";

	return 0;
}
