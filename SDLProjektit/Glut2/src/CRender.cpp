#include "CRender.h"
#include <gl/glut.h>
#include"apu/helpFunctions.h"
#include "apu/Bmp_image.h"
#include"cVector3f.h"
//#include"apu/bmp_loader.h"

const char WorldData[] = "world.txt";

CRender::CRender()
{
    //ctor
}

CRender::~CRender()
{
    delete iTerrain;
}


void CRender::switchLighingOn()
{

    if(ligthing) return;

   glEnable (GL_LIGHTING);
    glEnable (GL_LIGHT0);
      glEnable (GL_LIGHT1);
      glEnable(GL_NORMALIZE);

   this->ligthing = true;
}

void CRender::switchLighing()
{

  if (!ligthing){

    glEnable (GL_LIGHTING);
    ligthing = true;
  }
  else
  {
    glDisable (GL_LIGHTING);
    ligthing = false;
  }


}
void CRender::addAmbientLight()
{
  GLfloat ambientColor[]= {0.2f, 0.2f, 0.2f, 1.0f}; // color is 0.2, 0.2, 0.2
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);



}


void CRender::addPositionLight()
{

    GLfloat lightColor0[] = {1.0f, 1.0f, 1.0f, 1.0f};// color is 0.5, 0.5, 0.5. last parameter is allways 1??
    GLfloat lighPos0[] = {4.0, 3.0f, 8.0f, 1.0f } ; // poxition is 4.0, 0 and  8  last allways 1 in pos light
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
     glLightfv(GL_LIGHT0, GL_POSITION, lighPos0);
}



void CRender::addDirectLight()
{
    GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f};
    GLfloat lightPos1[] = {5.0f, 3.0f, 1.0f, 0.0f}; //light from direction -1, 0.5 and  0.5  last para is  allways 0 in direct light
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
     glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

}

void CRender::initFog()
{


    GLfloat fogColor[] = {0.5f, 0.5f, 0.5f, 1};
 GLfloat density = 0.3f;
    glFogfv(GL_FOG_COLOR,fogColor);
    glFogf(GL_FOG_DENSITY,density);
    glFogi(GL_FOG_MODE, GL_LINEAR);
   glHint(GL_FOG_HINT,GL_NICEST);
    glFogf(GL_FOG_START, 0.0f);
    glFogf(GL_FOG_END, 10.0f);

    fog = true;
}



void CRender::switchFogOn()
{
    if(fog) return;
    glEnable(GL_FOG);
    fog = true;
}


void CRender::switchFog()
{
     if (!fog){

    glEnable (GL_FOG);
    fog = true;
  }
  else
  {
    glDisable (GL_FOG);
    fog = false;
  }
}


void CRender::setup3dWorld()
{
    float x, y, z, u, v ;
    FILE *filein;
	char line[255]="";
    int  numTriangles;

      try{
		filein = fopen(WorldData, "rt");
		readStrToFile(filein, line);

       sscanf(line, "NUMPOLLIES %d\n", &numTriangles);
       wordl.triangle = new TRIANGLE[numTriangles];
     wordl.numTriages = numTriangles;
    for(int i=0; i<numTriangles; i++)
    {
        for(int j=0; j<3; j++)
        {
           readStrToFile(filein,line);
            sscanf(line, "%f %f %f %f %f", &x, &y, &z, &u, &v);
             wordl.triangle[i].vertex[j].x = x;
             wordl.triangle[i].vertex[j].y = y;
             wordl.triangle[i].vertex[j].z = z;
             wordl.triangle[i].vertex[j].u = u;
             wordl.triangle[i].vertex[j].v = v;
        }

    }


      }
 catch(...){

           //return ;
           }


if(filein) fclose(filein);
return;

}

void CRender::draw3dWorld()
{
  GLfloat x_m, y_m, z_m, u_m, v_m;
  int numTriangles = wordl.numTriages;

  glTranslated(0.0f, 0.05f, 0.0f);
glPushMatrix();
 for(int i; i<numTriangles; i++)
  {

	glBegin(GL_TRIANGLES);
			glNormal3f( 0.0f, 0.0f, 1.0f);

            x_m = wordl.triangle[i].vertex[0].x;
            y_m = wordl.triangle[i].vertex[0].y;
            z_m = wordl.triangle[i].vertex[0].z;
            u_m = wordl.triangle[i].vertex[0].u;
            v_m = wordl.triangle[i].vertex[0].v;
            glTexCoord2f(u_m,v_m); glVertex3f(x_m,y_m,z_m);


            x_m = wordl.triangle[i].vertex[1].x;
            y_m = wordl.triangle[i].vertex[1].y;
            z_m = wordl.triangle[i].vertex[1].z;
            u_m = wordl.triangle[i].vertex[1].u;
            v_m = wordl.triangle[i].vertex[1].v;
               glTexCoord2f(u_m,v_m); glVertex3f(x_m,y_m,z_m);




            x_m = wordl.triangle[i].vertex[2].x;
            y_m = wordl.triangle[i].vertex[2].y;
            z_m = wordl.triangle[i].vertex[2].z;
            u_m = wordl.triangle[i].vertex[2].u;
            v_m = wordl.triangle[i].vertex[2].v;
            glTexCoord2f(u_m,v_m); glVertex3f(x_m,y_m,z_m);

glEnd();
  }

 glPopMatrix();


}

GLuint CRender::load_texture(Bmp_image *image)
{

 GLuint textureID;


glGenTextures(1, &textureID);
glBindTexture(GL_TEXTURE_2D, textureID);

glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,image->Witdh(),image->Height(),0,GL_RGB,GL_UNSIGNED_BYTE,image->Pixels());

return textureID;
}







void CRender::setupSkyBox()
{








}



void CRender::drawSkyBox()
{
            glPushMatrix();
            glColor4f(1,1,1,1);

              glPushAttrib(GL_ENABLE_BIT);
              glEnable(GL_TEXTURE_2D);






            glBegin(GL_QUADS);
            // front
           glVertex3f(0.5f, -0.5f, -0.5f);

             glVertex3f(-0.5f, -0.5f, -0.5f);

              glVertex3f(-0.5f, 0.5f, -0.5f);

               glVertex3f(0.5f, 0.5f, -0.5f);

            glEnd();

      //left
        glBegin(GL_QUADS);

             glVertex3f(0.5f, -0.5f, 0.5f);

              glVertex3f(0.5f, 0.5f, -0.5f);

               glVertex3f(0.5f, 0.5f, 0.5f);

        glEnd();


     //back
       glBegin(GL_QUADS);






       glEnd();



       //right
           glBegin(GL_QUADS);


           glEnd();






       //top

       glBegin(GL_QUADS);





       glEnd();





       // bottom

        glBegin(GL_QUADS);




        glEnd();


 glPopMatrix();
}


void CRender::drawRoom()
{
    Bmp_image *image = load_bitmap("mud.bmp");
    iTextureID = load_texture(image);
     delete image;

glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,iTextureID);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);



glBegin(GL_QUADS);
/* Floor */
glTexCoord2f(0.0f, 0.0f);
glVertex3f(-1,-1,-1);

glTexCoord2f(1.0f, 0.0f);
glVertex3f(10,-1,-1);

glTexCoord2f(0.0f, 1.0f);
glVertex3f(10,-1,10);

glTexCoord2f(1.0f, 1.0f);
glVertex3f(-1,-1,10);



/* Ceiling */

glTexCoord2f(0.0f, 0.0f);
glVertex3f(-1,5,-1);

glTexCoord2f(1.0f, 0.0f);
glVertex3f(10,5,-1);

glTexCoord2f(0.0f, 1.0f);
glVertex3f(10,5,10);

glTexCoord2f(1.0f, 1.0f);
glVertex3f(-1,5,10);


/* Walls */
//
//glTexCoord2f(0.0f, 0.0f);
//glVertex3f(-1,-1,10);
//glTexCoord2f(1.0f, 0.0f);
//glVertex3f(10,-1,10);
//glTexCoord2f(0.0f, 1.0f);
//glVertex3f(10,5,10);
//glTexCoord2f(1.0f, 1.0f);
//glVertex3f(-1,5,10);


glTexCoord2f(0.0f, 0.0f);
glVertex3f(-1.0f,-1.0f,-1.0f);
glTexCoord2f(1.0f, 0.0f);
glVertex3f(10.0f,-1.0f,-1.0f);
glTexCoord2f(0.0f, 1.0f);
glVertex3f(10.0f,5.0f,-1);
glTexCoord2f(1.0f, 1.0f);
glVertex3f(-1.0f,5.0f,-1.0f);

glTexCoord2f(0.0f, 0.0f);
glVertex3f(10.0f,5.0f,10.0f);
glTexCoord2f(1.0f, 0.0f);
glVertex3f(10,-1,10);
glTexCoord2f(0.0f, 1.0f);
glVertex3f(10,-1,-1);
glTexCoord2f(1.0f, 1.0f);
glVertex3f(10,5,-1);


glTexCoord2f(0.0f, 0.0f);
glVertex3f(-1,5,10);
glTexCoord2f(1.0f, 0.0f);
glVertex3f(-1,-1,10);
glTexCoord2f(0.0f, 1.0f);
glVertex3f(-1,-1,-1);
glTexCoord2f(1.0f, 1.0f);
glVertex3f(-1,5,-1);

glEnd();

}


void CRender::load_terrain()
{
     Bmp_image* bm;

      //cBitmap* bm;
    // bm->LoadBMP("hmap.bmp");

    bm = load_bitmap("hmap.bmp");



 iTerrain = new cTerrain(bm->Witdh(), bm->Height());
//
	for(int y = 0; y < bm->Height(); y++) {
		for(int x = 0; x <bm->Witdh(); x++) {
			unsigned char color =
				(unsigned char)bm->pixels[3 * (y * bm->Witdh() + x)];




		//unsigned char *color = bm->Pixels(3*(y * bm->Witdh() + x));
			 //char *color = bm->pixels[3 * (y * bm->Witdh() + x)];

		//float h = height * ((color / 255.0f) - 0.5f);


		float h = TERRAIN_H * ((color / 255.0f) - 0.5f);
			iTerrain->set_H(x, y, h);

		}

    }

	delete bm;
}



void CRender::draw_terrain()
{


	glColor3f(0.3f, 0.9f, 0.0f);
	for(int z = 0; z < iTerrain->get_l() - 1; z++) {
		//Makes OpenGL draw a triangle at every three consecutive vertices
		glBegin(GL_TRIANGLE_STRIP);
		for(int x = 0; x < iTerrain->get_w(); x++) {
           cVector3f normal = iTerrain->get_normal(x, z);
			glNormal3f(normal[0], normal[1], normal[2]);
			glVertex3f(x, iTerrain->get_H(x, z), z);

     		normal = iTerrain->get_normal(x, z + 1);
    		glNormal3f(normal[0], normal[1], normal[2]);
			glVertex3f(x, iTerrain->get_H(x, z + 1), z + 1);
            }
		glEnd();
	}
}
