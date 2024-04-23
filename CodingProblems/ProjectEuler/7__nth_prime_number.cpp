/*
 * Find the Nth prime number
 *
 * Here it's 10,001st
 */

#include <iostream>
#include <cmath>

bool isPrime(int& number);

int main(void) {
	int counter = 10000;
	int tmp{1};

	while (counter) {
		// skipping even numbers
		tmp += 2;
		if (isPrime(tmp)) counter --;
	}

	std::cout << "The 10,001st prime: " << tmp << "\n";

	return 0;
}

bool isPrime(int& number) {
	double sqrt = std::sqrt(number);

	for (int i = 3; i <= sqrt; ++i) {
		if (number % i == 0) return false;
	}

	return true;
}
