#include "cMouse.h"

cMouse::cMouse()

{
    x = 0;
    y = 0;
}

cMouse::~cMouse()
{
    //dtor
}

 void cMouse::init()
{
 x = 0;
 y = 0;
 buttons[GLUT_LEFT_BUTTON] = GLUT_UP;
 buttons[GLUT_MIDDLE_BUTTON] = GLUT_UP;
 buttons[GLUT_RIGHT_BUTTON] = GLUT_UP;
}

void cMouse::button()
{

}

void cMouse::move()
{

}

void cMouse::serX(const int  aX)
{
    x = aX;

}

void cMouse::setY(const int aY)
{
    y = aY ;
}



const int cMouse::getX() const
{
    return x ;
}


const int cMouse::getY() const
{
    return y ;
}



