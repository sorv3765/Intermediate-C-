#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

using std::string;
using std::ostream;

class Shape				// This is the base class!
{
	public:
		Shape(const string&);	//constructor
		virtual ~Shape();		//desctructor
		virtual void print();		//print
		virtual double get_area();

	protected:
		string color;

};

//*************** Constructor *****************
Shape::Shape()
{
	area = 0;
	perimeter = 0;
}

//*************** Destructor *****************
Shape::~Shape()
{
	delete [] color;

}

//*************** Print *****************
Shape::print()
{

 cout << color << endl;

}

//*************** Get Area *****************

Shape::Shape
double Shape::get_area()
{
	return area;
}

#endif
