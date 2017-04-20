#include "cCamera.h"

cCamera::cCamera()
{
    //ctor
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    lastX = 0.0f;
    lastY = 0.0f;
    lastZ = 0.0f;
}

cCamera::~cCamera()
{
    //dtor
}


void cCamera::setCord(float aX, float aY, float aZ)
{
    x = aX;
    y = aY;
    z = aZ;
}


const float cCamera::getX() const
{
    return x;
}

const float cCamera::getY() const
{
    return y;

}

const float cCamera::getZ() const
{
    return z;
}
