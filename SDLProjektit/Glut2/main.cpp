

//
//
//
//#include <GL/gl.h>
//#include <GL/glut.h>
//#include <stdlib.h>
//#include <math.h>
//
////angle of rotation
//float xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0, angle=0.0;
//
//float lastx, lasty;
//
////positions of the cubes
//float positionz[10];
//float positionx[10];
//
//void cubepositions (void) { //set the positions of the cubes
//
//    for (int i=0;i<10;i++)
//    {
//    positionz[i] = rand()%5 + 5;
//    positionx[i] = rand()%5 + 5;
//    }
//}
//
////draw the cube
//void cube (void) {
//    for (int i=0;i<10;i++)
//    {
//    glPushMatrix();
//    glTranslated(-positionx[i + 1] * 10, 0, -positionz[i + 1] *
//10); //translate the cube
//    glutSolidCube(2); //draw the cube
//    glPopMatrix();
//    }
//}
//
//void init (void) {
//cubepositions();
//}
//
//void enable (void) {
//    glEnable (GL_DEPTH_TEST); //enable the depth testing
//    glEnable (GL_LIGHTING); //enable the lighting
//    glEnable (GL_LIGHT0); //enable LIGHT0, our Diffuse Light
//    glShadeModel (GL_SMOOTH); //set the shader to smooth shader
//
//}
//
//void camera (void) {
//    glRotatef(xrot,1.0,0.0,0.0);  //rotate our camera on teh x-axis (left and right)
//    glRotatef(yrot,0.0,1.0,0.0);  //rotate our camera on the y-axis (up and down)
//    glTranslated(-xpos,-ypos,-zpos); //translate the screenn to the position of our camera
//}
//
//void display (void) {
//    glClearColor (0.0,0.0,0.0,1.0); //clear the screen to black
//    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
//    glLoadIdentity();
//    camera();
//    enable();
//    cube(); //call the cube drawing function
//    glutSwapBuffers(); //swap the buffers
//    angle++; //increase the angle
//}
//
//void reshape (int w, int h) {
//    glViewport (0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the current window specifications
//    glMatrixMode (GL_PROJECTION); //set the matrix to projection
//
//    glLoadIdentity ();
//    gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 1000.0); //set the perspective (angle of sight, width, height, ,depth)
//    glMatrixMode (GL_MODELVIEW); //set the matrix back to model
//
//}
//void keyboard (unsigned char key, int x, int y)
//{
//    if (key=='q')
//    {
//    xrot += 1;
//    if (xrot >360) xrot -= 360;
//    }
//
//    if (key=='z')
//    {
//    xrot -= 1;
//    if (xrot < -360) xrot += 360;
//    }
//
//    if (key=='w')
//    {
//    float xrotrad, yrotrad;
//    yrotrad = (yrot / 180 * 3.141592654f);
//    xrotrad = (xrot / 180 * 3.141592654f);
//    xpos += float(sin(yrotrad)) ;
//    zpos -= float(cos(yrotrad)) ;
//    ypos -= float(sin(xrotrad)) ;
//    }
//
//    if (key=='s')
//    {
//    float xrotrad, yrotrad;
//    yrotrad = (yrot / 180 * 3.141592654f);
//    xrotrad = (xrot / 180 * 3.141592654f);
//    xpos -= float(sin(yrotrad));
//    zpos += float(cos(yrotrad)) ;
//    ypos += float(sin(xrotrad));
//    }
//
//    if (key=='d')
//    {
//    float yrotrad;
//    yrotrad = (yrot / 180 * 3.141592654f);
//    xpos += float(cos(yrotrad)) * 0.2;
//    zpos += float(sin(yrotrad)) * 0.2;
//    }
//
//    if (key=='a')
//    {
//    float yrotrad;
//    yrotrad = (yrot / 180 * 3.141592654f);
//    xpos -= float(cos(yrotrad)) * 0.2;
//    zpos -= float(sin(yrotrad)) * 0.2;
//    }
//
//    if (key==27)
//    {
//    exit(0);
//    }
//}
//
//void mouseMovement(int x, int y) {
//    int diffx=x-lastx; //check the difference between the current x and the last x position
//    int diffy=y-lasty; //check the difference between the current y and the last y position
//    lastx=x; //set lastx to the current x position
//    lasty=y; //set lasty to the current y position
//    xrot += (float) diffy; //set the xrot to xrot with the addition of the difference in the y position
//    yrot += (float) diffx;    //set the xrot to yrot with the addition of the difference in the x position
//}
//
//int main (int argc, char **argv) {
//    glutInit (&argc, argv);
//    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH);
//    glutInitWindowSize (500, 500);
//    glutInitWindowPosition (100, 100);
//    glutCreateWindow ("A basic OpenGL Window");
//    init ();
//    glutDisplayFunc (display);
//    glutIdleFunc (display);
//    glutReshapeFunc (reshape);
//
//    glutPassiveMotionFunc(mouseMovement); //check for mouse  movement
//
//    glutKeyboardFunc (keyboard);
//    glutMainLoop ();
//    return 0;
//}
//



/*
 * glutbase.c -- glut base application
 * last modification: aug. 14, 2007
 *
 * Copyright (c) 2005-2007 David HENRY
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * gcc -Wall -ansi -lGL -lGLU -lglut glutbase.c -o glutbase
 */
//
//#include <GL/glut.h>
//#include <stdlib.h>
//#include <string.h>
//#include"cGameEngine.h"
//#include"cKeyboard.h"
//#include "cMouse.h"
////#include"apu/OBJStruckture.h"
//
//
//cGameEngine game;
//
//
//
//static void
//cleanup ()
//{
//
//
//
//
//}
////
//static void
//init ()
//{
//
//   game.initOpenGL();
//
//}
//
///**
// * GLUT's reshape callback function.
// * Update the viewport and the projection matrix.
// */
//static void
//reshape (int w, int h)
//{
//  if (h == 0)
//    h = 1;
//
//  glViewport (0, 0, (GLsizei)w, (GLsizei)h);
//
//  glMatrixMode (GL_PROJECTION);
//  glLoadIdentity ();
//  gluPerspective (45.0, (GLfloat)w/(GLfloat)h, 0.1, 1000.0);
//
//  glMatrixMode (GL_MODELVIEW);
// // glLoadIdentity ();
//
// // glutPostRedisplay ();
//}
//
//
///**
// * GLUT's display callback function.
// * Render the main OpenGL scene.
// */
//static void
//display ()
//{
//
//game.display();
//
//}
//
///**
// * GLUT's Key press callback function.
// * Called when user press a key.
// */
//static void
//keyPress (unsigned char key, int x, int y)
//{
//
//       game.HandleKey(key);
//
//}
//
///**
// * GLUT's Key up callback function.
// * Called when user release a key.
// */
//static void
//keyUp (unsigned char key, int x, int y)
//{
//
//   game.HandleKeyUp(key);
//
//
// // keyboard.keymap[key] = 0;
//}
//
///**
// * GLUT's Key press callback function.
// * Called when user press a special key.
// */
//static void
//specialKeyPress (int key, int x, int y)
//{
//   game.SpecialDown(key);
//
//}
//
///**
// * GLUT's key up callback function.
// * Called when user release a special key.
//*/
//static void
//specialKeyUp (int key, int x, int y)
//{
//  game.SpecialUp(key);
//}

///**
// * GLUT's mouse motion callback function.
// * Called when the user move the mouse. Update the
// * camera.
// */
//static void
//mouseMotion (int x, int y)
//{
//
//
//    game.MouseMotion(x,y);
//
//
//
//}
//
//
//
//
///**
// * GLUT's mouse button callback function.
// * Called when the user press a mouse button. Update mouse
// * state and keyboard modifiers.
// */
//static void
//mouseButton (int button, int state, int x, int y)
//{
//
//    game.mouseButtonState(button, state, x, y);
//
//
//}
//
///**
// * GLUT's idle callback function.
// * Continuously called. Perform background processing tasks.
// */
//static void
//idleVisible ()
//{
////  /* Update the timer */
//         game.update();
//
//}
//
///**
// * GLUT's window status callback function.
// * Called when the status of the window changes.
// */
//static void windowStatus (int state)
//{
//  /* Disable rendering and/or animation when the
//     window is not visible */
//  if ((state != GLUT_HIDDEN) &&
//      (state != GLUT_FULLY_COVERED))
//    {
//      glutIdleFunc (idleVisible);
//    }
//  else
//    {
//      glutIdleFunc (NULL);
//    }
//}
//
///**
// * This is the main program.
// */
//int main (int argc, char *argv[])
//{
//  /* Initialize GLUT */
//  glutInit (&argc, argv);
//
//  /* Create an OpenGL window */
//  glutInitDisplayMode ( GLUT_DOUBLE | GLUT_DEPTH);
//  glutInitWindowSize (640, 480);
//  glutCreateWindow ("Tea");
//
//  /* Initialize application */
//  atexit (cleanup);
//
//  init ();
//
//
//
//  /* Setup GLUT's callback functions */
//glutReshapeFunc (reshape);
////
//glutDisplayFunc (display);
//  glutKeyboardFunc (keyPress);
//  glutKeyboardUpFunc (keyUp);
//  glutSpecialFunc (specialKeyPress);
//   glutSpecialUpFunc (specialKeyUp);
//  glutPassiveMotionFunc(mouseMotion);
//  glutMotionFunc (mouseMotion);
//  glutMouseFunc (mouseButton);
//  glutWindowStatusFunc (windowStatus);
//  glutIdleFunc (idleVisible);
//
//  /* Enter the main loop */
//  glutMainLoop ();
//
//  return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//



#include<gl\glut.h>

#include <iostream>
#include<math.h>



using namespace std;
float _cam_angle = 10.0f;
float _angle_Y = 25.0f;
float _angle_X = 10.0f;
float _cam_dist = 3.0f;

int widht = 800;
int heigt = 600;
int xMouse = 0;
int yMouse = 0;

GLfloat mat_ambient[] = {0.5, 0.5, 0.5, 1.0};
GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat mat_shininess[] = {50.0};
GLfloat light_position[] = {10.0, 10.0, 10.0, 0.0};
GLfloat model_ambient[] = {1.0, 0.5, 0.5, 1.0};

void setupMaterials()
{
//	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
}

void changeColour(GLfloat r, GLfloat g, GLfloat b, GLfloat A)
{
//	model_ambient[0] = r;
//	model_ambient[1] = g;
//	model_ambient[2] = b;
//	model_ambient[3] = A;
//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
}


void init(void)
{
	glClearColor(0.7, 0.9, 1.0,1.0);
//	setupMaterials();
//
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_CULL_FACE);
//	glFrontFace(GL_CCW);
	glShadeModel(GL_SMOOTH);
}


void reshape(int w, int h)
{
	GLfloat fAspect;
	if(h==0) h=1;

	glViewport(0,0,w,h);

	fAspect = (GLfloat)w / (GLfloat)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60, fAspect, 0.5, 100.0);
	glTranslatef(0,0,-1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void display(void)
{
       static float time = 0.0f;
       time += 0.01f;
       float xCam;
       float yCam;
       float zCam;
       float xUp;
       float yUp;
       float zUp;




//	int slices = 30;
//	int stacks = 30;
//	float radius = 0.2;
//
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//


      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();

      xCam = cos(_angle_X*2.0f*3.14f/360.0f)*_cam_dist
                                            *sin(_angle_Y*2.0f*3.14f/360.0f);

      yCam = sin(_angle_X*2.0f*3.14f/360.0f)*_cam_dist;

      zCam = cos(_angle_X*2.0f*3.14f/360.0f)*_cam_dist
                                            *cos(_angle_Y*2.0f*3.14f/360.0f);


     xUp = -sin(_angle_X*2.0f*3.14f/360.0f)*sin(_angle_Y*2.0f*3.14f/360.0f);
     yUp =  cos(_angle_X*2.0f*3.14f/360.0f);
     zUp = -sin(_angle_X*2.0f*3.14f/360.0f)*cos(_angle_Y*2.0f*3.14f/360.0f);


    gluLookAt(xCam,yCam,zCam,0.0f,0.0f,0.0f,xUp,yUp,zUp);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(float)widht/(float)heigt, 0.1f, 100);


glMatrixMode(GL_MODELVIEW);

    glNormal3f(0.0f,0.0f,1.0f);

 //glRotatef(_cam_angle,180.0f,360.0f,180.0f);

    glBegin(GL_TRIANGLES);

    glColor3f(1.0f,0.0f,0.75f);
    glVertex3f(0.0f,0.0f,0.0f);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(1.0f,0.0f,0.0f);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.0f,1.0f,0.0f);
   glEnd(); // glMatrixMode(GL_MODELVIEW);

//glBegin(GL_QUADS);
//
//glColor3f(0.0f,0.0f,1.0f);
//    glVertex3f(0.0f,0.0f,0.0f);
//    glVertex3f(2.0f,0.0f,0.0f);
//    glVertex3f(2.0f,2.0f,0.0f);
//      glVertex3f(0.0f,2.0f,0.0f);
//
//glEnd();

  // glPushMatrix();
//        changeColour(0.8, 0.0, 0.0, 0.0);
//        glTranslatef(0.0, 0.0, 0.1);
     //   glRotatef(_cam_angle,1.0f,0.0f,0.0f);
//        glutSolidSphere(radius, slices, stacks);
   // glPopMatrix();
//
//	glFlush();
    glutSwapBuffers();
}



void keyboard(unsigned char key, int x, int y)
{
	switch (key) {

      case 'w':
      _cam_dist -= 0.1f;
       if(_cam_dist<0.1f) _cam_dist = 0.1f;

        break;


		case 's':
		_cam_dist += 0.1f;
		break;

        case'q':
        exit(0);
        break;

		case 27:
			exit(0); // Exit the application if 'Esc' key is pressed
	        break;
	}
}

void mouse(int button, int state, int x, int y )
{
// xMouse = x;
 //yMouse = y;
}

void motition(int x, int y)
{
    _angle_X += x - xMouse;
    _angle_Y += y - yMouse;

    if(_angle_X >= 360.0f) _angle_X -= 360.0f;
    if(_angle_X < 0.0f)    _angle_X += 360.0f;
    if(_angle_Y >= 360.0f) _angle_Y -= 360.0f;
    if(_angle_Y < 0.0f)    _angle_Y += 360.0f;
      _angle_X = x;
      _angle_Y = y;

glutPostRedisplay();
}





void animate() {

	if(_cam_angle>=360.0f)_cam_angle -=360.0f;
	_cam_angle+= 0.20f;

	glutPostRedisplay();

}




int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
      glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
       glutInitWindowSize (800, 600);
   glutCreateWindow ("Kuvioita Demo");
    init();

glutDisplayFunc (display);

    glutKeyboardFunc (keyboard);
   glutMouseFunc(mouse);
   glutMotionFunc(motition);

    glutReshapeFunc (reshape);
    glutIdleFunc(animate);
    glutMainLoop();
    return 0;
}
