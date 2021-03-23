#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <iomanip>
#include "shape.h"

using std::string
using std::ostream;

class Circle: public Shape
{
public:
	Circle(string, int);
	void print();
	double get_area();

protected:
	int radius;
};

//*************** Constructor *****************
Circle::Circle( string color, int radius)
{
	Shape()= color;
}

//*************** Overridden Print *****************
void Shape::print() const
{
	Circle::print();

	cout << color << " circle, " << "radius " << radius <<", area " << area << endl;

}

//*************** Overridden get_area *****************
double Shape::get_area() const
{
	Circle::get_area();
}
#endif
