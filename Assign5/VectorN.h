#ifndef VECTORN_H
	#define VECTORN_H

#include <iostream>

using namespace std;

class VectorN
{
friend std::ostream& operator<<(std::ostream& , const VectorN&);
friend VectorN operator*(double, const VectorN&);

	private:
		double *vectorArray;
		size_t vectorSize;
	public:
		VectorN();								//default constructor
		VectorN(double [], size_t);					//constructor  that intialize a new vectorN object
		VectorN(const VectorN&);					//copy constructor
		~VectorN();								//destructor for VectorN

		VectorN& operator=(const VectorN&);			//overloaded copy assignment operator
		size_t size() const;							// return size of vector
		VectorN operator+(const VectorN&) const;
		VectorN operator-(const VectorN&) const;
		double  operator*(const VectorN&) const;
		VectorN operator*(double) const;
		void clear();
		double& operator[](int);
		double operator[](int) const;
		double at(int) const;
		double& at(int);
		bool operator==(const VectorN&) const;
};

#endif
