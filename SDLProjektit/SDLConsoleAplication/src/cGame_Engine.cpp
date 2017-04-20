#include "cGame_Engine.h"

cGame_Engine::cGame_Engine()
{
    SCREENWIDH = 640;
    SCREENHEIGHT = 480;
    SCREENBIT = 32;
}

cGame_Engine::~cGame_Engine()
{
    //dtor
}
bool cGame_Engine::Alusta_SDL()
{

    SDL_Init(SDL_INIT_EVERYTHING);
     naytto = SDL_SetVideoMode(SCREENWIDH, SCREENHEIGHT, SCREENBIT, SDL_HWSURFACE|SDL_DOUBLEBUF);
    return true;
}

void cGame_Engine::Kayta_Engine()
{

}

void cGame_Engine::SetTiedoston_Nimi(const string nimi)
{
    Tiedoston_nimi = nimi;
}

const string cGame_Engine::Get_Tiedoston_nimi() const
{
    return Tiedoston_nimi;
}

void cGame_Engine::Lataa_Kuva()
{
      kuva = SDL_DisplayFormat(kuva);
      const char *apu = Tiedoston_nimi.c_str();

      kuva = IMG_Load(apu);

}

void cGame_Engine::Piirra_Kuva()
{
    SDL_BlitSurface(kuva,NULL,naytto,NULL);
    SDL_Flip(naytto);
     SDL_Delay(5000);
}


void cGame_Engine::Kasittele_kuvaa()
{
   kuva = rotozoomSurface(kuva,0,1,1);

}



void cGame_Engine::Tuhoa_Kuva()
{
SDL_FreeSurface(kuva);
}


void cGame_Engine::Tuhoa_SDL()
{
  SDL_Quit();
}






