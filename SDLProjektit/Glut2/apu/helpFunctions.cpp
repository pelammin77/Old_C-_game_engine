#include"helpFunctions.h"

void readStrToFile(FILE *f,char *string)
{
	do
	{
		fgets(string, 255, f);
	} while ((string[0] == '/') || (string[0] == '\n'));
	return;
}




char strequal(const char *s1, const char *s2)
{
	if(strcmp(s1, s2) == 0)
		return 1;
	return 0;
}

char contains(const char *haystack, const char *needle)
{
	if(strstr(haystack, needle) == NULL)
		return 0;
	return 1;
}





AUX_RGBImageRec *LoadBMP(char *Filename)
{

}
