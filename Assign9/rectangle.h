#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle : public Shape
{
	public:
		Rectangle(int width, int height);
		void print()();
		double get_area();

	protected:
		int width, height;

};

#include "shape.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle(float width, float length)
{

	width = width;
	length = length;
}

float Rectangle::get_area()
{
	int result;
	result= width*length;

	return result;
}

float Rectangle::get_perimeter()
{
	int result;
	result=2*(length+width);

	return result;
}

#endif
