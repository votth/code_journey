#include <iostream>
using namespace std;

#include "shape.h"
#include "oval.h"
#include "circle.h"

int main(void) {
	Shape shape1("Shape1");
	shape1.draw();

	Oval oval1(2.0, 3.5, "Oval1");
	oval1.draw();

	Circle circle1(3.3, "Circle1");
	circle1.draw();

	// Using base ptr
	Shape *shape_collection[] {&shape1, &oval1, &circle1};

	for (Shape *s_ptr : shape_collection) {
		s_ptr->draw();
	}

	return 0;
}
