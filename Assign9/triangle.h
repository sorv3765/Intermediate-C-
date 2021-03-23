#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle : public Shape{

	public:
		Triangle(float base, float height);
		float get_area();

	private:
		float base, height;

};

#include "shape.h"
#include "rectangle.h"
#include "square.h"
#include <iostream>

using namespace std;


Triangle::Triangle(float base, float height)
{
	base = base;
	height = height;
}

float Triangle::get_area()
{
	return (0.5*base*height);
}

#endif
