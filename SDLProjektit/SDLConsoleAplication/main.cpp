#include"include/cGame_Engine.h"
#include <SDL/SDL_mixer.h>

int main(int argc, char *argv[])
{
   cGame_Engine game;
   game.Alusta_SDL();
   game.SetTiedoston_Nimi("UfoIlmanTaustaa.png");
   game.Lataa_Kuva();
   game.Kasittele_kuvaa();
   game.Piirra_Kuva();
  game.Tuhoa_Kuva();
  game.Tuhoa_SDL();
   return 0;

}




  /*

VANHA TESTIOHJELMA

-------------------------------------------------------------------------------------------------

    const int SCREENWIDH = 640;
    const int SCREENHEIGHT = 480;
    const int SCREENBIT = 32;




int main(int argc, char *argv[])

    SDL_Surface *naytto;
   SDL_Surface *kuva;
     SDL_Init(SDL_INIT_EVERYTHING);
     naytto = SDL_SetVideoMode(SCREENWIDH, SCREENHEIGHT, SCREENBIT, SDL_HWSURFACE|SDL_DOUBLEBUF);
    //kuva = SDL_LoadBMP("moku.bmp");
    kuva = IMG_Load("ufo.png");
    SDL_BlitSurface(kuva,NULL,naytto,NULL);
        SDL_Flip(naytto);
     SDL_Delay(5000);

    SDL_FreeSurface(kuva);
        SDL_Quit();

     return 0;







///vielä vanhempi piirtää 1 pikselin ruudulle

int main(int argc, char *argv[])
{

SDL_Surface *naytto;

    Uint8 *p;
    int x = 100  ;
    int y= 400;



    p = (Uint8*) naytto->pixels + y* naytto->pitch + x* naytto->format->BytesPerPixel;
       *p=0xff;
        SDL_Delay(5000);


         SDL_Quit();


   return 0;
*/


