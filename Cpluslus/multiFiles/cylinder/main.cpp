#include <iostream>
#include "constants.h" // not needed here since it's called in cylinder.h already, but having here to show that #ifndef works
#include "cylinder.h"


int main(void) {
	Cylinder cylinder1(10, 4);

	std::cout << "Volume: " << cylinder1.volume() << std::endl;

	Cylinder *p_c1 = &cylinder1;
	std::cout << "Volume of ptr: " << p_c1->volume() << std::endl;

	Cylinder *p_c2 = new Cylinder(100, 2);
	std::cout << "Volume of p_c2: " << p_c2->volume() << std::endl;

	delete p_c2;
	return 0;
}
