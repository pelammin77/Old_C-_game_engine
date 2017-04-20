#ifndef CRENDER_H
#define CRENDER_H
#include"apu/Bmp_image.h"
#include <GL/glut.h>
#include"cTerrain.h"

#define TERRAIN_H 15
#define HMAPFILE "hmap.bmp"

typedef struct tagVertex
{
    float x, y, z;// x, y and z cordinates
    float u, v;// textures



} VERTEX;


typedef struct tagTriangle
{

    VERTEX vertex[3];

} TRIANGLE;


typedef struct tagIndoor
{
     int numTriages;
     TRIANGLE *triangle;

} INDOOR;

class CRender
{
    public:
        CRender();
        virtual ~CRender();
        void switchLighing();
        void switchLighingOn();
        void switchFog();
        void switchFogOn();
        void setup3dWorld();
        void draw3dWorld();
        void setupSkyBox();
        void drawSkyBox();

        void drawRoom();
        void load_terrain();
        void  draw_terrain();
      const   bool getLightingState() const {return ligthing; }
      const bool isFogOn() const{return fog;}
       void addAmbientLight();
       void addPositionLight();
       void addDirectLight();
       void initFog();
    protected:
      INDOOR wordl;
        bool ligthing;
        bool fog;
        cTerrain *iTerrain;
        GLuint iTextureID;
        GLuint load_texture(Bmp_image *image);
    private:
};

#endif // CRENDER_H
