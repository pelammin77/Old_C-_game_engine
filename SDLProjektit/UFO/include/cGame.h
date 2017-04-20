#ifndef CGAME_H
#define CGAME_H
#include<SDL/SDL.h>
#include<SDL/SDL_Image.h>


#include"cScope.h"
#include "cUfo.h"
#include<iostream>
//#include<vector>
using namespace std;
class cGame
{
    public:
        cGame();
        virtual ~cGame();
        bool Create_New_Game();
        void Run_Game();

        void End_Game();
    protected:
        cScope iScope;
        SDL_Surface *Screen;
        SDL_Surface *Backround;
        int screenH, screenW, screenBit;
        cUfo ufos[5];
        int lkm_Ufo;
        bool game_on;

         void Draw_Scope();
     void Draw_Ufos();
        void Update_Game_State();
        void Create_Scope();

      // vector<cUfo> Game_ufos;

    private:
    void Create_New_Ufo();
};

#endif // CGAME_H
