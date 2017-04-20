#ifndef CMOUSE_H
#define CMOUSE_H

#include<GL/glut.h>
#include"cKeyboard.h"
class cMouse
{
    public:
        cMouse();
        virtual ~cMouse();
        int buttons[3];
        void init();
        void move();
         void button();
         void serX(const int aX);
         void setY(const int aY);
       const int getX() const ;
       const int getY() const ;
       cMouse getMouse()const {return *this;}
        int getButtons(){ if(buttons[GLUT_RIGHT_BUTTON]) return 1;
                           else if(buttons[GLUT_LEFT_BUTTON]) return 2;
                           else if(buttons[GLUT_MIDDLE_BUTTON]) return 3;
                            else return 0;
           }

    protected:
    int x , y;

   // cKeyboard& iKeyboard;
    private:
};

#endif // CMOUSE_H
