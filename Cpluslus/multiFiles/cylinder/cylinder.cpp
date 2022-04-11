#include "cylinder.h"

// Cylinder:: is to specify where the method belongs
Cylinder::Cylinder(double rad_param, double height_param) {
	base_rad = rad_param;
	height = height_param;
}
// Getters and Setters
double Cylinder::get_base_rad() {
	return base_rad;
}
double Cylinder::get_height() {
	return height;
}
//
void Cylinder::set_base_rad(double rad_param) {
	base_rad = rad_param;
}
void Cylinder::set_height(double height_param) {
	height = height_param;
}
// Other methods
double Cylinder::volume() {
	return pi * base_rad * base_rad * height;
}
