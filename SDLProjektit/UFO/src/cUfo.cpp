#include "cUfo.h"

cUfo::cUfo():CBase_Sprite()
{
    //ctor
    file_name = "Game_ufo.png";
}

cUfo::~cUfo()
{
  //  SDL_FreeSurface(img);
    //dtor
}
void cUfo::Draw(SDL_Surface *scr)
{
    CBase_Sprite::Draw(scr);
//SDL_BlitSurface(img,NULL,scr,NULL);
}
