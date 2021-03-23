#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Vector3.h"

using namespace std;

/*******************************************************************
// Method:      Vector3::Vecotr3(double x, double y, double z)
// Use:         default constructor for the Vector3 class
// Arguments:   double x, y, z
// Returns:     nothing
*********************************************************************/
Vector3::Vector3(double x, double y, double z)
{
	vector_arr[0]=x;	//set x in  position 0
	vector_arr[1]=y;	//set y in position 1
	vector_arr[2]=z;	//setz in position 2
}

/*******************************************************************************************
// Method:      Vector3 Vector3::operator+(const Vector3& RightVar) const
// Use: 	overload + operator
// Arguments:	Vector3, RightVar
// Returns:	result vecoter data type
*******************************************************************************************/
Vector3 Vector3::operator+(const Vector3& RightVar) const
{

//this does the addition

	Vector3 result= *this;
	result.vector_arr[0]=result.vector_arr[0]+RightVar.vector_arr[0];
	result.vector_arr[1]=result.vector_arr[1]+RightVar.vector_arr[1];
	result.vector_arr[2]=result.vector_arr[2]+RightVar.vector_arr[2];

	return result;
}

/*******************************************************************************************
// Method:                      Vector3 Vector3::operator-(const Vector3& RightVar) const
// Use:                         overload - operator
// Arguments/varivables:        Vector3, RightVar
// Returns:                     result vector data type
*******************************************************************************************/
Vector3 Vector3::operator-(const Vector3& RightVar) const
{

//this does the subtraction

	Vector3 result= *this;
	result.vector_arr[0]-=RightVar.vector_arr[0];
	result.vector_arr[1]-=RightVar.vector_arr[1];
	result.vector_arr[2]-=RightVar.vector_arr[2];

	return result;
}

/*********************************************************************************************
// Method:           ostream& operator<<(ostream& leftVar, const Vector3& rightVar)
// Use:              overload <<  operator
// Arguments:        leftVar, RightVar
// Returns:          leftVar
*********************************************************************************************/
ostream& operator<<(ostream& leftVar, const Vector3& rightVar)
{

//this does provide the output

	leftVar<<"(";
	leftVar<<rightVar.vector_arr[0] <<", ";
	leftVar<<rightVar.vector_arr[1] <<", ";
	leftVar<<rightVar.vector_arr[2] <<")";

	return leftVar;
}

/*********************************************************************************************
// Method:           double Vector3::operator*(const Vector3& RightVar)const
// Use:              overload *  operator
// Arguments:        RightVar
// Returns:          product
*********************************************************************************************/
double Vector3::operator*(const Vector3& RightVar)const
{

//this does the multiplication in form of scalar product

	Vector3 result= *this;
	double product;
	product=(result.vector_arr[0]*RightVar.vector_arr[0])+(result.vector_arr[1]*RightVar.vector_arr[1])+(result.vector_arr[2]*RightVar.vector_arr[2]);

	return product;
}

/*********************************************************************************************
// Method:           Vector3 Vector3::operator*(double RightVar)const
// Use:              overload *  operator
// Arguments:        double RightVar
// Returns:          result vector data
*********************************************************************************************/
Vector3 Vector3::operator*(double RightVar)const
{

//this does multiplication of vector by CONSTANT in that order

	Vector3 result =*this;
	result.vector_arr[0]=result.vector_arr[0]*RightVar;
	result.vector_arr[1]=result.vector_arr[1]*RightVar;
	result.vector_arr[2]=result.vector_arr[2]*RightVar;

	return result;
}

/*********************************************************************************************
// Method:                      Vector3 operator*(double LeftVar, const Vector3& RightVar)
// Use:                         overload *  operator
// Arguments:        double LeftVar Vector3 RightVar
// Returns:                     result vector data
*********************************************************************************************/
Vector3 operator*(double LeftVar, const Vector3& RightVar)
{

//does  multiplication of the constant by the VECTOR in that order

	Vector3 result=RightVar;
	result.vector_arr[0]*=LeftVar;
	result.vector_arr[1]*=LeftVar;
	result.vector_arr[2]*=LeftVar;

	return result;
}

/*********************************************************************************************
// Method:                      double Vector3::operator[](int indx)const
// Use:                         overload [] operator
// Arguments:        int indx
// Returns:                     vector_arr[indx] valuse of class specified
*********************************************************************************************/
double Vector3::operator[](int indx)const
{

//this is the accessor methods for getting a value

	return vector_arr[indx];
}

/*********************************************************************************************
// Method:           double& Vector3::operator[](int indx)
// Use:              overload [] operator
// Arguments:        int indx
// Returns:          vector_arr[indx] valuse of class specified
*********************************************************************************************/
double& Vector3::operator[](int indx)
{

//this is the accessor methods for setting a value
        return vector_arr[indx];
}

/*********************************************************************************************
// Method:           bool Vector3::operator==(const Vector3& RightVar)const
// Use:              overload == operator
// Arguments:        Vector3 RightVar
// Returns:          true, or faulse boolian value
*********************************************************************************************/
bool Vector3::operator==(const Vector3& RightVar)const
{

//the two vectors are considered equal only if they are compnonent wise equal

	if((vector_arr[0]==RightVar.vector_arr[0]) && (vector_arr[1]==RightVar.vector_arr[1])&&(vector_arr[2]==RightVar.vector_arr[2]))
	{
		return true;
	}
	else
	{
		return false;
	}

}
