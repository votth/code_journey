#include "io.h"

#include <iostream>

int readNumber()
{
	int tmp;
	std::cout << "Your input: ";
	std::cin >> tmp;
	return tmp;
}

void writeAnswer(int answer)
{
	std::cout << "Your addition result: " << answer << '\n';
}
