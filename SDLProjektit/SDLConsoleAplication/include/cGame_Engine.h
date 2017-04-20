#ifndef CGAME_ENGINE_H
#define CGAME_ENGINE_H


#include<SDL\SDL.h>
#include<SDL\SDL_image.h>
#include <SDL/SDL_rotozoom.h>

#include<String>

using namespace std;

class cGame_Engine
{
    public:
        cGame_Engine();
        virtual ~cGame_Engine();
        virtual bool Alusta_SDL();
        virtual void Kayta_Engine();
                void Lataa_Kuva();
                void Tuhoa_Kuva();
                void Tuhoa_SDL();
                void SetTiedoston_Nimi( const string nimi);
                const string Get_Tiedoston_nimi() const;
                void Piirra_Kuva();
                void Kasittele_kuvaa();

    protected:
              int SCREENWIDH   ;
              int SCREENHEIGHT  ;
              int SCREENBIT ;
              SDL_Surface *naytto;
              SDL_Surface *kuva;
            SDL_Surface *Zoom_Kuva;
             string Tiedoston_nimi;
    private:



};

#endif // CGAME_ENGINE_H
