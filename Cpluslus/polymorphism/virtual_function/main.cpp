#include <iostream>
using namespace std;
// Headers
#include "shape.h"
#include "oval.h"
#include "circle.h"

void draw_shape(Shape *s) {
	s->draw();
}
void draw_shape(const Shape &s) {
	s.draw();
}

int main(void) {

	Shape shape1{"Shape1"};
	Oval oval1{2.0, 3.5, "Oval1"};
	Circle circle1{3.3, "Circle1"};

	// Using base ptr
	// without `virtual`, s_ptr->draw() only call Shape's draw()
	// but now it's using dynmically Oval and Circle method
	Shape *shape_collection[] {&shape1, &oval1, &circle1};
	// Shape shape_collection[] {...};
	// this will 'slice' off data

	for (Shape *s_ptr : shape_collection) {
		s_ptr->draw();
	}

	draw_shape(&oval1);
	draw_shape(&circle1);

	return 0;
}
