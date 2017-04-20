#ifndef CGAMEENGINE_H
#define CGAMEENGINE_H



#include"InterfaceInportHandler.h"
#include"cCamera.h"
#include"cTimer.h"
#include"cKeyboard.h"
#include"cMouse.h"
#include"CRender.h"
class cGameEngine
{
    public:



        cGameEngine();
      virtual ~cGameEngine();


         void initOpenGL();
         void display();
         void HandleKey(unsigned char key);
         void HandleKeyUp(unsigned char key);
         void SpecialDown(int key);
         void SpecialUp(int key);
         void mouseButtonState( int button, int state, int x, int y);
     void MouseMotion(int x, int y);
     void update();



     void LeftMouseButtonMotion(int x, int y);
     void RightMouseButtonMotion(int x, int y);
     void ShiftButtonDown(int x,int y);

    protected:

    void zoom(int x, int y);
    void rotation(int x, int y);
    void transition(int x, int y );
     void walkUp();
     void walkBack() ;
     void walkLeft();
     void walkRigth();
    cCamera eye;
    cCamera rot;
    cTimer timer;
    cKeyboard k1;
    cMouse  mouse;
     CRender render;



    private:
};

#endif // CGAMEENGINE_H
