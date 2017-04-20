#ifndef SDL_ENGINE_H
#define SDL_ENGINE_H

// Headers files

#include<SDL\SDL.h>
#include<SDL\SDL_image.h>


class SDL_Engine
{
    public:
        SDL_Engine();
        virtual ~SDL_Engine();
        void run();
        bool alusta();
        void tuhos();

    protected:
    private:
};

#endif // SDL_ENGINE_H
