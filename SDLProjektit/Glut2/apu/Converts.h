#ifndef CONVERTS_H_INCLUDED
#define CONVERTS_H_INCLUDED

#include <fstream>
using namespace std;


bool littleEndian();
int toInt(const char* bytes);
short toShort(const char* bytes);
unsigned short toUShort(const char* bytes);
float toFloat(const char* bytes);
int readInt(ifstream &input);
float readFloat(ifstream &input);
short readShort(ifstream &input);
unsigned short readUShort(ifstream &input);

#endif // CONVERTS_H_INCLUDED
