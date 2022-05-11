#include "io.h"
#include <iostream>

int main()
{
	int a{}, b{};
	a = readNumber();
	b = readNumber();

	int answer = a + b;
	writeAnswer(answer);

	return 0;
}
