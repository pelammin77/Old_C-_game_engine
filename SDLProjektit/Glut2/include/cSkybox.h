#ifndef CSKYBOX_H
#define CSKYBOX_H
#include<gl/gl.h>

#define SKY 0
#define FRONT 1
#define BACK 2
#define LEFT 3
#define RIGHT 4
#define BOTTOM 5

class cSkyBox
{
    public:
         cSkyBox(float aX, float aY, float aZ, float h, float l, float w, bool bottom );
        virtual ~cSkyBox();
        void draw_skybox();
        int storage_texture(char id, GLuint &tex);
    protected:
    private:
      float x;
      float y;
      float z;
      float height ;
      float length;
      float width;
      GLuint textures[6];
      bool draw_bottom;

    private:



};

#endif // CSKYBOX_H
