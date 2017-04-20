#include "CBase_Sprite.h"

CBase_Sprite::CBase_Sprite()
{
    //ctor
}

CBase_Sprite::~CBase_Sprite()
{

}


void CBase_Sprite::Load_Image()
{
   // img =SDL_DisplayFormat(img);
     const char *m = file_name.c_str();
    IMG_Load(m);
}




void CBase_Sprite::Draw(SDL_Surface *scr)
{
 SDL_BlitSurface(img,NULL,scr,NULL);
//SDL_Flip(scr);
}

void CBase_Sprite::Dstr_Sprite()
{
 delete this;
}
