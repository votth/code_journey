#include <iostream>
#include "person.h"

struct Point {
	double m_x{};
	double m_y{};
};

int main(void) {

	Person p1("John Snow", 35);
	p1.print_info();

	return 0;
}
