#include "cSkybox.h"


cSkyBox::cSkyBox(float aX, float aY, float aZ, float h, float l, float w, bool bottom)
{
  x = aX;
  y = aY;
  z = aZ;
  height = h;
  length = l;
  width = w;
  draw_bottom = bottom;
}

cSkyBox::~cSkyBox()
{
    //dtor
}

void cSkyBox::draw_skybox()
{
     // Center the skybox
   x = x - width  / 2;
   y = y - height / 2;
   z = z - length / 2;



     //draw back

   glBegin(GL_QUADS);
      glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y,         z);
      glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
      glTexCoord2f(0.0f, 1.0f); glVertex3f(x,         y + height, z);
      glTexCoord2f(0.0f, 0.0f); glVertex3f(x,         y,         z);
   glEnd();


//draw front
  glBegin(GL_QUADS);
      glTexCoord2f(1.0f, 0.0f); glVertex3f(x,         y,         z + length);
      glTexCoord2f(1.0f, 1.0f); glVertex3f(x,         y + height, z + length);
      glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
      glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y,         z + length);
  glEnd();

//draw sky
    glBegin(GL_QUADS);
      glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z);
      glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y + height, z + length);
      glTexCoord2f(1.0f, 1.0f); glVertex3f(x,         y + height,   z + length);
      glTexCoord2f(0.0f, 1.0f); glVertex3f(x,         y + height,   z);
   glEnd();


//draw left
 //glBindTexture(GL_TEXTURE_2D, textures[LEFT_ID]);
   glBegin(GL_QUADS);
   glTexCoord2f(1.0f, 1.0f); glVertex3f(x,         y + height,   z);
   glTexCoord2f(0.0f, 1.0f); glVertex3f(x,         y + height,   z + length);
   glTexCoord2f(0.0f, 0.0f); glVertex3f(x,         y,         z + length);
   glTexCoord2f(1.0f, 0.0f); glVertex3f(x,         y,         z);
   glEnd();


//draw right
//glBindTexture(GL_TEXTURE_2D, textures[RIGHT_ID]);
   glBegin(GL_QUADS);
      glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y,         z);
      glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y,         z + length);
      glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height,   z + length);
      glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height,   z);
   glEnd();



   if(draw_bottom)
   {
       //glBindTexture(GL_TEXTURE_2D, textures[BOTTOM_ID]);

   glBegin(GL_QUADS);
      glTexCoord2f(1.0f, 0.0f); glVertex3f(x,         y,         z);
      glTexCoord2f(1.0f, 1.0f); glVertex3f(x,         y,         z + length);
      glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y,         z + length);
      glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y,         z);
   glEnd();
   }

}

int cSkyBox::storage_texture(char id, GLuint &tex)
{
    switch(id)
    {
        case 'b': textures[BACK] = tex;
        break;

        case 'f': textures[FRONT] = tex;
        break;

        case 's': textures[SKY] = tex;
        break;

        case 'r': textures[RIGHT] = tex;
        break;

        case 'l': textures[LEFT] = tex;
        break;

        case 'g': textures[BOTTOM] = tex;
        break;

        default: return -1;


    }


  return 0;
}
