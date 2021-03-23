#ifndef VECTOR3_H
        #define VECOTR3_H

#include <iostream>

class Vector3
{
friend std::ostream& operator<<(std::ostream& , const Vector3&);
friend Vector3 operator*(double, const Vector3&);

private:
        double vector_arr[3];

public:
        Vector3(double=0, double=0, double=0);
        Vector3 operator+(const Vector3&) const;
        Vector3 operator-(const Vector3&) const;
        double operator*(const Vector3&) const;
        Vector3 operator*(double) const;
        double operator[](int) const;
        double& operator[](int);
        bool operator==(const Vector3&)const;
};

#endif
