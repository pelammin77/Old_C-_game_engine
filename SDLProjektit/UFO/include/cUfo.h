#ifndef CUFO_H
#define CUFO_H

#include<CBase_Sprite.h>

class cUfo:public CBase_Sprite
{
    public:
        cUfo();
        virtual ~cUfo();
       virtual void Draw(SDL_Surface *src);
    protected:
    int speed;
    void Animate();
    private:
};

#endif // CUFO_H
