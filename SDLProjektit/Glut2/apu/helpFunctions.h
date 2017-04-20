#ifndef HELPFUNCTIONS_H_INCLUDED
#define HELPFUNCTIONS_H_INCLUDED

#include <windows.h>		// Header File For Windows
#include <math.h>			// Math Library Header File
#include <stdio.h>	        // Header File For Standard Input/Output
#include"bmp.h"



char strequal(const char *s1, const char *s2);

char contains(const char *haystack, const char *needle);

 void readStrToFile(FILE *f,char *string);              //reads a line in the file
 AUX_RGBImageRec *LoadBMP(char *Filename) ;           // Loads A Bitmap Image

#endif // HELPFUNCTIONS_H_INCLUDED
