#ifndef CBASE_SPRITE_H
#define CBASE_SPRITE_H


#include<iostream>
#include<SDL\SDL.h>
#include<SDL\SDL_image.h>
using namespace std;

class CBase_Sprite
{
    public:
        CBase_Sprite();
        virtual ~CBase_Sprite();
      virtual void Draw(SDL_Surface *scr);
         virtual     void Load_Image();
    virtual void Dstr_Sprite();

    protected:
    string file_name;
    int XPosition, YPosition ;
    SDL_Surface * img;
    void move_sprite();
    private:
};

#endif // CBASE_SPRITE_H
