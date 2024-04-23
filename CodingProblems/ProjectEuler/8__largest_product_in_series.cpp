/* 
 * The four adjacent digits in the 1000-digit number (below) that have the greatest product are 9 x 9 x 8 x 9 = 5832.
 *
 * The number: 8__the_number.txt
 *
 * Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product.
 */

#include <iostream>
#include <fstream>
#include <array>

int main(void) {
	std::fstream fp{};
	char c{};
	std::array<int, 1000> numbers{};

	int curr{}, chase{};
	int count{0};
	// !!! value overflow
	long double prod{1}, maxProd{0};

	fp.open("./8__the_number.txt");
	if (!fp.is_open()) {
		std::cout << "Error opening file!\n";
		return 1;
	}
	// Fill up array with digits
	curr = 0;
	chase = curr;
	while (!fp.eof()) {
		fp.get(c);
		std::cout << c;
		if ('0' <= c && c <= '9') {
			numbers.at(curr) = c - '0';
			++curr;
		}
	}
	fp.close();
	std::cout << "\n";

	for (curr = 0; curr < 1000; ++curr) {
		if (numbers.at(curr) == 0) {
			prod = 1;
			count = 0;
			chase = curr+1;
			continue;
		}

		prod *= numbers.at(curr);
		++count;

		if (count == 13) {
			std::cout << prod << "\n";
			if (prod > maxProd) maxProd = prod;
			while ( curr + 1 < 1000 ) {
				if (numbers.at(curr + 1) == 0) break;
				curr++;
				prod = prod / numbers.at(chase) * numbers.at(curr);
			std::cout << prod << "\n";
				if (prod > maxProd) maxProd = prod;
				++chase;
			}
		}
	}

	/* for (curr = 0; curr < 1000 - 13; ++curr) { */
	/* 	prod = 1; */
	/* 	for (chase = 0; chase < 13; ++chase) { */
	/* 		std::cout << numbers.at(curr + chase); */
	/* 		prod *= numbers.at(curr + chase); */
	/* 	} */
	/* 	std::cout << "\n"; */
	/* 	if (prod > maxProd) maxProd = prod; */
	/* } */

	std::cout << "The result: " << maxProd << "\n";

	return 0;
}
