#include "cKeyboard.h"




cKeyboard::cKeyboard()

{
    //ctor

    KeyPressed = false;
    SpecialPressed = false;
     this->setKeyBoard();
}


cKeyboard::~cKeyboard()
{
    //dtor
}

void cKeyboard::setKeyBoard()
{
    memset(keyMap,0,256);
    memset(special,0,256);
}


void cKeyboard::setKeyState(unsigned char key)
{
 keyMap[key] = 1;

}


void cKeyboard::keyPress(unsigned char key)
{
keyMap[key] = 1;
KeyPressed = true;
}

void cKeyboard::keyUp(unsigned char key)
{
keyMap[key] = 0;
KeyPressed = false;
}


void cKeyboard::specialKeyPress(int key)
{
 special[key] = 1;
SpecialPressed = true;


}



void cKeyboard::specialKeyUp(int key)
{
   special[key] = 0;
   SpecialPressed = false;
}


const bool cKeyboard::IsKeyPressed() const
{
    return KeyPressed;
}


const bool cKeyboard::IsSpecialPressed() const
{
    return SpecialPressed;
}
