#include"Converts.h"


bool littleEndian()
{
    short s = 1;
    return (((char*)&s)[0]) == 1;

}


int toInt(const char* bytes)
{
  return (int)(((unsigned char)bytes[3] << 24) |
					 ((unsigned char)bytes[2] << 16) |
					 ((unsigned char)bytes[1] << 8) |
					 (unsigned char)bytes[0]);
}

float toFloat(const char* bytes)
{
	float f;
		if (littleEndian()) {
			((char*)&f)[0] = bytes[0];
			((char*)&f)[1] = bytes[1];
			((char*)&f)[2] = bytes[2];
			((char*)&f)[3] = bytes[3];
		}
		else {
			((char*)&f)[0] = bytes[3];
			((char*)&f)[1] = bytes[2];
			((char*)&f)[2] = bytes[1];
			((char*)&f)[3] = bytes[0];
		}
		return f;
}

short toShort(const char* bytes)
{
    return (short)(((unsigned char)bytes[1] << 8) |
					   (unsigned char)bytes[0]);
}

unsigned short toUShort(const char* bytes)
{
   return (unsigned short)(((unsigned char)bytes[1] << 8) |
								(unsigned char)bytes[0]);
}

int readInt(ifstream &input)
{
    char buffer[4];
    	input.read(buffer, 4);
		return toInt(buffer);

}

float readFloat(ifstream &input)
{
    char buffer[4];
		input.read(buffer, 4);
		return toFloat(buffer);
}


short readShort(ifstream &input)
{
    char buffer[2];
		input.read(buffer, 2);
		return toShort(buffer);
}

unsigned short readUShort(ifstream &input)
{
     char buffer[2];
		input.read(buffer, 2);
		return toShort(buffer);
}
