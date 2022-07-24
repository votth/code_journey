#include <iostream>
#include <string>

int fib(int n);

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Please provide a number.\n";
		return 1;
	}

	int number = std::stoi(argv[1]);

	std::cout << "The " << number << "th number's value is: " << fib(number) << "\n";

	return 0;
}

// memoization
//		fast access time container: 

int fib(int n) {
	if (n <= 2) return 1;
	return fib(n - 1) + fib(n - 2);
}
