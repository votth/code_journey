#include "circle.h"

Circle::Circle(double rad, string_view description)
	: Oval(rad, rad, description) {}

Circle::~Circle() {}
