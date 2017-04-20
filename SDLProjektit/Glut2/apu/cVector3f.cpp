#include "cVector3f.h"
#include<math.h>

cVector3f::cVector3f()
{
    //ctor
}


cVector3f::cVector3f(float x, float y, float z)
{
    vector[0] = x;
    vector[1] = y;
    vector[2] = z;
}


cVector3f::~cVector3f()
{
    //dtor
}


float cVector3f::operator[](int index) const
{
 return vector[index];
}


float &cVector3f::operator[](int index)
{
 return vector[index];
}


cVector3f cVector3f::operator* (float scale) const
{
    return cVector3f(vector[0]*scale, vector[1]*scale, vector[2]*scale);
}


cVector3f cVector3f::operator/(float scale) const
{
    return cVector3f(vector[0]/scale, vector[1]/scale, vector[2]/scale);
}


cVector3f cVector3f::operator+(const cVector3f &other) const
{
   return cVector3f(vector[0] + other.vector[0], vector[1] + other.vector[1], vector[2]+ other.vector[2]);
}

cVector3f cVector3f::operator-(const cVector3f &other) const
{
    return cVector3f(vector[0] - other.vector[0], vector[1] - other.vector[1], vector[2] - other.vector[2]);
}

cVector3f cVector3f::operator-() const
{
     return cVector3f(-vector[0], -vector[1], -vector[2]);

}

const cVector3f &cVector3f::operator*= (float scale)
{
    vector[0] *= scale;
	vector[1] *= scale;
	vector[2] *= scale;
	return *this;
}

const cVector3f &cVector3f::operator/= (float scale)
{
    vector[0] /= scale;
	vector[1] /= scale;
	vector[2] /= scale;
	return *this;
}




const cVector3f &cVector3f::operator+=(const cVector3f &other)
{
  vector[0] += other.vector[0];
	vector[1] += other.vector[1];
	vector[2] += other.vector[2];
	return *this;
}


const cVector3f &cVector3f::operator-=(const cVector3f &other)
{
    vector[0] -= other.vector[0];
	vector[1] -= other.vector[1];
	vector[2] -= other.vector[2];
	return *this;
}

float cVector3f::magnitude() const
{
    return sqrt(vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2]);
}



float cVector3f::magnitudeSquared() const
{
    return vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2];
}


cVector3f cVector3f::normalize() const
{
   	float m = sqrt(vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2]);
	return cVector3f(vector[0] / m, vector[1] / m, vector[2] / m);
}


float cVector3f::dot(const cVector3f &other) const
{
  return vector[0] * other.vector[0] + vector[1] * other.vector[1] + vector[2] * other.vector[2];
}


cVector3f cVector3f::cross(const cVector3f &other) const
{

    return cVector3f(vector[1] * other.vector[2] - vector[2] * other.vector[1],
				 vector[2] * other.vector[0] - vector[0] * other.vector[2],
				 vector[0] * other.vector[1] - vector[1] * other.vector[0]);

}


cVector3f operator*(float scale, const cVector3f &v)
{
    return v * scale;
}


std::ostream &operator<<(std::ostream &output, const cVector3f &v)
{
    std::cout << '(' << v[0] << ", " << v[1] << ", " << v[2] << ')';
	return output;
}
