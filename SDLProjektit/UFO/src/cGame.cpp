#include "cGame.h"

cGame::cGame()
{

    screenH = 480;
    screenW = 640;
    screenBit = 32;
    //ctor
}

cGame::~cGame()
{
    SDL_FreeSurface(Backround);
     delete ufos;

     SDL_Quit();
}


bool cGame::Create_New_Game()
{
   // if(game_on) return false;
   SDL_Init(SDL_INIT_EVERYTHING);
     Screen = SDL_SetVideoMode(screenW, screenH, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
 // Backround = SDL_DisplayFormat(Backround);
  Backround =IMG_Load("Backround.png");
  SDL_BlitSurface(Backround,NULL,Screen,NULL);

      this->Create_Scope();

    //    SDL_BlitSurface(iScope,NULL,Screen,NULL);


        this->Update_Game_State();
        SDL_Delay(5000);



   // game_on = true;
    return true;
}

void cGame::Create_Scope()
{
    iScope.Load_Image();
    this->Draw_Scope();
}



void cGame::Create_New_Ufo()
{
    if(lkm_Ufo>=5) return;
   cUfo ufo;
  ufo.Load_Image();
 ufos[lkm_Ufo]= ufo ;
  lkm_Ufo++;
  this->Draw_Ufos();
   ufo.Draw(Screen);

}


void cGame::Draw_Scope()
{
    iScope.Draw(Screen);
}

void cGame::Draw_Ufos()
{
    for(int i; i<lkm_Ufo; i++)
     {
     cUfo u;
    u = ufos[i];
    u.Draw(Screen);
     }
    this-> Update_Game_State();
   //Käydään taulukko läpi piirretään kaikki ufot tähtäin  näytölle
}
void cGame::Update_Game_State()
{
  SDL_Flip(Screen);
}


