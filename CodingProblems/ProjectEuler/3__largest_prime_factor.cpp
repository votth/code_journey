/*
 * The prime factor of 13,195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600,851,475,143?
 */
#include <iostream>
#include <cmath>

template<typename T>
bool ifPrime(T &number);

int main(void) {
	long int target = 600851475143;
	int limit = std::sqrt(target);

	int i = 2;
	int factor{};

	// If target is prime itself
	if ( ifPrime(target) ) {
		std::cout << target << " is a prime number\n";
	} else {
		std::cout << target << " is NOT a prime number\n";
	}

	// Finding the factor
	i = 3;
	while (i < limit) {
		if (ifPrime(i)) {
			if (target % i == 0) {
				factor = i;
				// skippin even divider
				i += 2;
				continue;
			}
		}
		i += 2;
	}

	std::cout << target << "'s largest prime factor: " << factor << std::endl;

	return 0;
}

template<typename T>
bool ifPrime(T &number) {
	// Possible upper limit of a number's prime factor
	T limit = std::sqrt(number);

	for (T i = 2; i < limit; ++i) {
		if ( number % i == 0 ) return false;
	}

	return true;
}
