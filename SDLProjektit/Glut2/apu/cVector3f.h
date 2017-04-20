#ifndef CVECTOR3F_H
#define CVECTOR3F_H

#include<iostream>

class cVector3f
{
    public:
        cVector3f();
        cVector3f(float x, float y, float z);
        virtual ~cVector3f();

        float &operator[](int index) ;
		float operator[](int index) const;

		cVector3f operator*(float scale) const;//kertolasku
		cVector3f operator/(float scale) const;// jakolasku
		cVector3f operator+(const cVector3f &other) const; //pluslasku ''
		cVector3f operator-(const cVector3f &other) const; // vähennyslasku
		cVector3f operator-() const; // käänteisvectori

		const cVector3f &operator*=(float scale); // kertoo vectorin
		const cVector3f &operator/=(float scale); // jakaa vektorin
		const cVector3f &operator+=(const cVector3f &other);
		const cVector3f &operator-=(const cVector3f &other);

		float magnitude() const; //magnitudi
		float magnitudeSquared() const; // neliöjuuri magnitudista
		cVector3f normalize() const; //normalisointi
		float dot(const cVector3f &other) const;//pistetulon laskenta
		cVector3f cross(const cVector3f &other) const;//ristitulon laskenta

    protected:
    private:

        float vector[3];
};

cVector3f operator*(float scale, const cVector3f &v);

std::ostream &operator<<(std::ostream &output, const cVector3f &v);

#endif // CVECTOR3F_H
