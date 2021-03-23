#include "shape.h"
#include "rectangle.h"
#include "triangle.h"
#include "square.h"
#include <iostream>

using namespace std;

int main()
{


	Rectangle rectangleObject(2,5);
	Triangle triangleObject(1,10);
	Square squareObject(5);

	cout << "The area of the rectangle is" << rectangleObject.get_area() << '\n';
	cout << "The perimeter of the rectangle is " << rectangleObject.get_perimeter() << '\n';
	cout << "The area of the triangle is " << triangleObject.get_area() << '\n';
	cout << "The area of the square is " << squareObject.get_area() << '\n';

	return 0;
}
