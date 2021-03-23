#ifndef SQUARE_H
#define SQUARE_H


class Square : public Rectangle{

	public:
		Square(float side);

	private:

};

#include "shape.h"
#include "triangle.h"
#include "rectangle.h"
#include <iostream>

using namespace std;

Square::Square(float side)
{
	Rectangle r(side,side);
}
#endif
