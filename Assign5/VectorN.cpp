#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "VectorN.h"

using namespace std;
using std::out_of_range;

/*************************************************
Default Constructor
*************************************************/
VectorN::VectorN()
{
	vectorSize = 0;			//numbers of value currently in array
	vectorArray = new double[vectorSize];	//pointer in array values

}

/************************************************
Constructor that intialize new VectorN object stored in the array values
*************************************************/
VectorN::VectorN(double values[], size_t n)
{
	vectorSize = n;					//set the Vector size for new objec to n

	if(vectorSize == 0)				//check if vector size is 0
	{
		vectorArray=nullptr;
	}
	else						//otherwise use the vector array pointer for the new object to allocate an array
	{
		vectorArray = new double[vectorSize];

		for (size_t i = 0; i < vectorSize; i++)	//copy the elements of the array values into the vector array
		{
			vectorArray[i] = values[i];
		}
	}
}

/*************************************************
Destructor
*************************************************/
VectorN::~VectorN()
{
	delete[] vectorArray;
}

/*************************************************
Copy Constructor
*************************************************/
VectorN::VectorN(const VectorN& other)
{

        vectorSize = other.vectorSize;			//set vector size of other
        vectorArray = new double[vectorSize];		//set vector array of other

        if(vectorSize < 0)
        {
                vectorSize = 0;
        }

        if(vectorSize == 0)				//If 0 set the array pointer to new object to nullptr
        {
                vectorArray=nullptr;
        }
        else						//Otherwise vector array pointer for new object to allocate an array 
        {
                vectorArray = new double[vectorSize];

                for (size_t i = 0; i < vectorSize; i++)	//copy the elements of array values into vector array
                {
                        vectorArray[i] = other.vectorArray[i];
                }
        }
}

/*************************************************
Output Operator
*************************************************/
ostream& operator<<(ostream &current, const VectorN& other)
{
	size_t i = 0;
	
	current << "(";
	if(other.vectorSize > 0)
	{
		for (i = 0; i < other.vectorSize - 1; i++)
		{
			current << other.vectorArray[i] << ", ";
    		}

		current << other.vectorArray[i];
	}

	current << ")";

	return current;
}

/*************************************************
Overloaded Assignment Operator
*************************************************/
VectorN& VectorN::operator=(const VectorN& other)
{
	if(this!=&other)				//self-assignment
	{
		vectorSize = other.vectorSize;		//vector size should be same for ovther.vectorsize

		delete [] vectorArray;			//delete vector array for object pointed to by this

        	if(vectorSize == 0)			// set the vector array pointer 
        	{
                	vectorArray=nullptr;
        	}
        	else					//Otherise use vector array pointer to allocate
        	{
                	vectorArray = new double[vectorSize];	//number of elements in new vector aray should be equal

                	for (size_t i = 0; i < vectorSize; i++)	//copy the content of the vector array of otherinto the vector array of the object pointed by this
                	{
                        vectorArray[i] = other.vectorArray[i];
                	}
        	}
	}

	return *this;
}

/*************************************************
Addition Operator
*************************************************/
VectorN VectorN::operator+(const VectorN& other)const
{
	VectorN result;

	if(vectorSize<other.vectorSize)
	{
		result= *this;

		for(size_t i = 0; i < vectorSize; i++)
        	{
        		result.vectorArray[i] += other.vectorArray[i];
        	}
	}
	else
	{
		result=other;

		for(size_t i = 0; i < other.vectorSize; i++)
		{
		result.vectorArray[i] += vectorArray[i];
		}
	}

	return result;
}

/*************************************************
Subtraction Operator
*************************************************/
VectorN VectorN::operator-(const VectorN& other)const
{
        {
        VectorN result;

        if(vectorSize<other.vectorSize)
        {
                result= *this;

                for(size_t i = 0; i < vectorSize; i++)
                {
                        result.vectorArray[i] -= other.vectorArray[i];
                }
        }
        else
        {
                result=other;

                for(size_t i = 0; i < other.vectorSize; i++)
                {
                result.vectorArray[i] -= vectorArray[i];
                }
        }

        return result;
}

}

/*************************************************
This does the multiplication in form of scalar product
*************************************************/

double VectorN::operator*(const VectorN& other)const
{
	size_t min;
	double product;
        VectorN result= *this;

	if(result.vectorSize<other.vectorSize)
		min=result.vectorSize;
	else
		min=other.vectorSize;
        for(size_t i = 0; i < min; i++)
	{
		product+=result.vectorArray[i]* other.vectorArray[i];
	}
        return product;
}

/*************************************************
This does multiplication of vector by CONSTANT in that order
*************************************************/
VectorN VectorN::operator*(double number)const
{

        VectorN result =*this;

	for(size_t i=0; i < result.vectorSize; i++)
	{
		result.vectorArray[i]*=number;
	}

        return result;
}

/************************************************
Does  multiplication of the constant by the VECTOR in that order
*************************************************/
VectorN operator*(double current, const VectorN& other)
{
        VectorN result= other;

	for(size_t i=0; i < result.vectorSize;i++)
	{
        	result.vectorArray[i]*=current;
	}

        return result;
}

/*************************************************
Return size of the Vector
*************************************************/
size_t VectorN::size() const
{
	return vectorSize;
}

/*************************************************
Instantly clears the data
*************************************************/
void VectorN::clear()
{
	delete [] vectorArray;
	vectorArray = nullptr;

	vectorSize = 0;

}

/*************************************************
Accessor Methods for the class (for getting a value)
*************************************************/
double& VectorN::operator[](int i)
{
	return vectorArray[i];
}

/*************************************************
Accessor Methods for the class (for setting a value)
*************************************************/
double VectorN::operator[](int i) const
{
	return vectorArray[i];
}

/*************************************************
Variant of the READ form of operator[] that provides some error checking.
*************************************************/
double VectorN::at(int sub) const
{
//Method of the READ FORM
	if( sub < 0 || sub >= (int)vectorSize)
		throw out_of_range("Out of Range");

	return vectorArray[sub];

}


/*************************************************
variant of the WRITE form of operator[] that provides some error checking.
*************************************************/
double& VectorN::at(int sub)
{
//Method of the WRITE FORM

	if( sub < 0 || sub >= (int)vectorSize)
		throw out_of_range("subscript is Out of Range");

	return vectorArray[sub];


}


/*************************************************
Equality Operator to compare two VectorNs
*************************************************/
bool VectorN::operator==(const VectorN& other)const
{

	if(vectorSize!=other.vectorSize)		//check if equal vector size
		return false;

	for(size_t m=0; m<vectorSize; m++)		//double check for each time
	{
		if(vectorArray[m]!= other.vectorArray[m])
			return false;
	}

	return true;
}

