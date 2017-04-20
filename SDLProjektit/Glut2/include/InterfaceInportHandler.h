#ifndef INTERFACEINPORTHANDLER_H_INCLUDED
#define INTERFACEINPORTHANDLER_H_INCLUDED

 class InterfaceInputHandler{

public:

    virtual void HandleKey(unsigned char key) = 0;
    virtual void MouseMotion(int x, int y)    = 0;
    virtual void LeftMouseButtonMotion(int x, int y) = 0;
    virtual void RightMouseButtonMotion(int x, int y) = 0;
    virtual void ShiftButtonDown(int x,int y) = 0;


 };





#endif // INTERFACEINPORTHANDLER_H_INCLUDED
