#ifndef OVAL_H
#define OVAL_H

#include "shape.h"

class Oval : public Shape {
	public:
		Oval() = default;
		Oval(double x_rad, double y_rad, string_view description);
		~Oval();

		void draw() const{
			cout << "Oval::draw() called of x: " << m_x_rad << " and y: " << m_y_rad << endl;
		}

	protected:
		double get_x_rad() const{
			return m_x_rad;
		}
		double get_y_rad() const{
			return m_y_rad;
		}

	private:
		double m_x_rad{};
		double m_y_rad{};
};

#endif // OVAL_H
