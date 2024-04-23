#include <iostream>

int main(void) {
	long int target = 600851475143;
	int i = 2;

	while ( target > 1 ) {
		if (!(target % i)) {
			target /= i;
			i--;
		}
		i++;
	}

	 std::cout << "Result is: " << i << std::endl;

	return 0;
}
