#ifndef CYLINDER_H
#define CYLINDER_H

#include "constants.h"

class Cylinder {
	private:
		// member objects/variables
		double base_rad{};
		double height{};
	public:
		// Default constructor
		Cylinder() = default;
		// Constructor with params
		Cylinder(double rad_param, double height_param);
		// Getters
		double get_base_rad();
		double get_height();
		// Setters
		void set_base_rad(double rad_param);
		void set_height(double height_param);
		// Other methods
		double volume();
};

#endif
