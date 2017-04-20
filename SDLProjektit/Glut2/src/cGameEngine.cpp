#include "cGameEngine.h"
#include<GL/glut.h>
#include<math.h>

cGameEngine::cGameEngine()
{


    cout<<"Ladataan"<<endl;



    // set up cameras
    eye.setCord(0.0f, 0.50f, 3.0f);
    mouse.init();

}

cGameEngine::~cGameEngine()
{

}


void cGameEngine::initOpenGL()
{
//init Open GL

    glClearColor (0.0f, 0.0f, 0.0f, 1.0f);
  glShadeModel (GL_SMOOTH);

  glEnable (GL_DEPTH_TEST);
  render.switchLighingOn();
  render.addAmbientLight();
   render.addPositionLight();
   render.addDirectLight();
// glEnable(GL_FOG);
// render.initFog();
 render.setup3dWorld();

 //render.switchFogOn();
}

void cGameEngine::display()
{
      glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glLoadIdentity ();
      //  glTranslated (-eye.x, -eye.y, -eye.z);
      glRotated (rot.x, -1.0f, 0.0f,0.0f);
      glRotated (rot.y, 0.0f, 1.0f, 0.0f);
      glRotated (rot.z, 0.0f, 0.0f, 1.0f);
       glTranslated (-eye.x, -eye.y, -eye.z);
glPushMatrix();

 glTranslated(0.0f, 0.0f, 1.0f);

   //render.draw3dWorld();
   // glPopMatrix();

    render.load_terrain();
    render.draw_terrain();
    // render.drawRoom();

   // glutSolidTeapot (1.0f);

 // glutSolidCube(5.0f);
  glPopMatrix();

  glutSwapBuffers ();




}
void cGameEngine::HandleKey(unsigned char key)
{




   // static int lightOn = 1;
   k1.setKeyState(key);




 //quit
  if (key == 'q')
    exit (0);

   if(key == 27)// escape
    exit (0);



//  /* 'l': toggle light */
     if (key == 'l')
     render.switchLighing();


    if(key == 'f')
    render.switchFog();

    if(key == 'w')
    walkUp();


if( key == 's')
    walkBack();

    if(key =='d')
    walkRigth();

    if(key == 'a')
    walkLeft();

  glutPostRedisplay ();


}

void cGameEngine::HandleKeyUp(unsigned char key)
{
    k1.keyUp(key);
}


void cGameEngine::SpecialDown(int key)
{
   k1.specialKeyPress(key);

}

void cGameEngine::SpecialUp(int key )
{

 k1.specialKeyUp(key);
}

void cGameEngine::MouseMotion(int x, int y)
{
int  button = mouse.getButtons();
   switch(button){


    case 1:
   {
       rotation(x, y);
     break  ;
   }


    case 2:
    {
     transition(x, y);
     break   ;
    }



    case 3:
    {
      break  ;
    }


  default:
   {
     rotation(x, y)   ;

   }


   }

mouse.serX(x);
mouse.setY(y);

 glutPostRedisplay ();


}

void cGameEngine::rotation(int x, int y)
{

mouse.serX(x-rot.lastX);
mouse.setY(y-rot.lastY);

rot.lastX = x;
rot.lastY = y;

rot.x-=(float) mouse.getY();
rot.y+=(float) mouse.getX();

if(rot.y>360.0f) rot.y-=360.0f;

//if(rot.lastX>= 360.0f) rot.lastX -= 360.0f;
//if(rot.lastX< 0)       rot.lastX += 360.0f;


//if(rot.lastY< 0)       rot.y += 90.0f;

//rot.x += (y - mouse.getY());
//rot.y += (x - mouse.getX());
//if(rot.x > 360.0f) rot.x = 360.0f;
//if (rot.y > 90.0f) rot.y = 90.0f;
//eye.x += (x - mouse.getX());
//eye.y += (y - mouse.getY());

}

void cGameEngine::zoom(int x, int y)
{
     eye.z += (x - mouse.getX()) * 0.1;

}


void cGameEngine::transition(int x, int y)
{

     if (k1.modifiers & GLUT_ACTIVE_SHIFT)
     {
  eye.x -= (x - mouse.getX()) * 0.02;
 //eye.y += (y - mouse.getY()) * 0.02;
     }
else zoom(x, y);


}
 void cGameEngine::walkBack()
 {

      float aX, aY;
     aX =( rot.getX()/ 180* 3.141592654f);
     aY = (rot.getY()/ 180* 3.141592654f);
     eye.x += float(sin(aY)) ;
     eye.z -= float(cos(aY));
    // eye.y -= float(sin(aX));

 }

void cGameEngine::walkUp()
{
      float aX, aY;
     aX =( rot.getX()/ 180* 3.141592654f);
     aY = (rot.getY()/ 180* 3.141592654f);
     eye.x -= float(sin(aY)) ;
     eye.z += float(cos(aY));
    // eye.y -= float(sin(aX));



}

void cGameEngine::walkRigth()
{
    float aY;
    aY = (rot.getY()/ 180* M_PI);
    eye.x += float(cos(aY))*0.2;
    eye.z += float(cos(aY))*0.2;
}


void cGameEngine::walkLeft()
{
 float aY;
    aY = (rot.getY()/ 180* M_PI);
    eye.x -= float(cos(aY))*0.2;
   eye.z -= float(cos(aY))*0.2;




}
void cGameEngine::mouseButtonState( int button, int state, int x, int y)
{

  /* Update key modifiers */
 k1.modifiers = glutGetModifiers ();
//
//  /* Update mouse state */
   mouse.buttons[button] = state;
  mouse.serX(x);
  mouse.setY(y);





}

void cGameEngine::update()
{
 timer.Update();
}




//___________________________________________________________________________


//Virtual functions for interface not used

void cGameEngine::LeftMouseButtonMotion(int x, int y)
{

}

void cGameEngine::RightMouseButtonMotion(int x, int y)
{

}

void cGameEngine::ShiftButtonDown(int x, int y)
{

}
//--------------------------------------------------------------------------------------------
