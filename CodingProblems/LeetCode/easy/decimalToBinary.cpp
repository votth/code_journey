#include <iostream>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Please provide a number between 0-255\n";
		return 1;
	}
	int input = std::stoi(argv[1]);
	if ((0 > input) || (input > 255)) {
		std::cout << "Please provide a number between 0-255\n";
		return 1;
	}

	int base = 2;
	int modulus[7]{};
	int i{};

	std::cout << "Input: " << input << std::endl;

	std::cout << "Output: ";
	for (i = 0; i < 8; ++i) {
		modulus[i] = input % 2;
		input /= 2;
	}
	for (i = 7; i >= 0; --i) {
		std::cout << modulus[i];
	}
	std::cout << std::endl;

	return 0;
}
