#include <iostream>

const double pi{3.1415926};

class Cylinder {
	private:
		// member objects/variables
		double base_radius{};
		double height{};
	public:
		// Default constructor
		Cylinder() = default;
		// Constructor with params
		Cylinder(double rad_param, double height_param) {
			base_radius = rad_param;
			height = height_param;
		}
		// Getters
		double get_base_rad() {
			return base_rad;
		}
		double get_height() {
			return height;
		}
		// Setters
		void set_base_rad(double rad_param) {
			base_rad = rad_param;
		}
		void set_height(double height_param) {
			height = height_param;
		}
		// Other methods
		double volume() {
			return pi * base_radius * base_radius * height;
		}
};

int main(void) {
	// This will fail if left empty as cylinder2()
	// therefore, we need default constructor
	Cylinder cylinder1(10, 4);
	/* cylinder1.base_radius = 3; */
	/* cylinder1.height = 5; */

	std::cout << "The volume of the cylinder1: " << cylinder1.volume() << std::endl;

	return 0;
}
