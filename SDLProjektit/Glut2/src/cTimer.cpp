#include <GL/glut.h>
#include "cTimer.h"

cTimer::cTimer()
{

    CurrentTime = 0;
    LastTime = 0;

    //ctor
}

cTimer::~cTimer()
{
    //dtor
}

void cTimer::Update()
{
    LastTime = CurrentTime;
    CurrentTime = (double)glutGet(GLUT_ELAPSED_TIME)* 0.001f;
}

void cTimer::SetTime(const double aTime)
{
    CurrentTime = aTime;
}
const double cTimer::GetCurrentTime()const
{
    return CurrentTime;
}

const double cTimer::GetLastTime() const
{
    return LastTime;
}
