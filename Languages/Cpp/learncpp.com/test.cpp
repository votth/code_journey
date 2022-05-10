#include <iostream>

int doubleNumber(int input);
void getUserInput(int* input);

int main() {
	int input {};
	getUserInput(&input);
	std::cout << "Double the number is: " << doubleNumber(input) << '\n';
	return 0;
}

int doubleNumber(int input) {
	return input * 2;
}

void getUserInput(int* input) {
	std::cout << "Your number: ";
	std::cin >> *input;
}
