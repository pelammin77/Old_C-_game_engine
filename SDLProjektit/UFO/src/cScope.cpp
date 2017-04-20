#include "cScope.h"

cScope::cScope():CBase_Sprite()
{
    file_name ="Scope.png";
    //ctor
}

cScope::~cScope()
{
    if(img) SDL_FreeSurface(img);

}
