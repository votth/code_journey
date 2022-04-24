#ifndef CIRCLE_H
#define CIRCLE_H

#include "oval.h"

class Circle : public Oval {
	public:
		Circle() = default;
		Circle(double rad, string_view description);
		~Circle();

		virtual void draw() const{
			cout << "Circle::draw() called of rad: " << get_x_rad() << endl;
		}

	private:
		double m_x_rad{};
		double m_y_rad{};
};

#endif // CIRCLE_H
