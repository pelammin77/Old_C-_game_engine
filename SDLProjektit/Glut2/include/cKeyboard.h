#ifndef CKEYBOARD_H
#define CKEYBOARD_H

#include <stdlib.h>
#include <string.h>
#include"InterfaceInportHandler.h"

class cKeyboard
{
    public:
        cKeyboard();
         int modifiers;



        virtual ~cKeyboard();
         void keyPress(unsigned char key);
         void keyUp(unsigned char key);
         void specialKeyPress(int key);
          void specialKeyUp(int key );
          void setKeyBoard();
          void setKeyState(unsigned char key);
           const  bool IsKeyPressed() const;
            const   bool IsSpecialPressed() const;


                 bool KeyPressed;
                 bool SpecialPressed;
                 bool modifiersPressed;
   protected:
      int keyMap[256];
      int special[256];



     private:
};

#endif // CKEYBOARD_H
