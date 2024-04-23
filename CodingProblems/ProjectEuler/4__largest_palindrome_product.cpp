/*
 * A palindromic number reads the same both ways.
 * The largest palindrome made from the product of two 2-digit numbers is 9,009 = 91 x 99 = 7 x 13 x 11 x 3 x 3
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <iostream>
#include <cmath>

bool isPalindrome(int& number);

int main(void) {

	int result{};
	int resultI{}, resultJ{};

	std::cout << "100 x 100 = " << 100 * 100 << std::endl;
	std::cout << "999 x 999 = " << 999 * 999 << std::endl;

	/* palindrome has to have even digit
	 * not a prime number
	 * has 11 as a factor ??? 121 ?
	 */

	/* if (argc == 1) { */
	/* 	std::cout << "Missing a number agrument.\n"; */
	/* 	return 1; */
	/* } */

	/* int test = std::atoi(argv[1]); */

	/* if (isPalindrome(test)) std::cout << "Is palindrom" << std::endl; */
	/* else std::cout << "is NOT palindrome\n"; */

	// Brute-force
	for (int i = 999; i >= 100; --i) {
		for (int j = i; j >= 100; --j) {
			int product = i * j;
			if (isPalindrome(product) && product > result) {
				result = product;
				resultI = i;
				resultJ = j;
			}
		}
	}

	std::cout << resultI << " x " << resultJ << " = " << result << std::endl;

	return 0;
}

bool isPalindrome(int& number) {
	int tmp = number;
	int rev = 0;

	while (tmp > 0) {
		rev = rev * 10 + (tmp % 10);
		tmp /= 10;
	}

	if (number == rev) return true;
	return false;
}
