#ifndef BMP_IMAGE_H
#define BMP_IMAGE_H

#include <fstream>

using namespace std;

class Bmp_image
{
    public:
        Bmp_image(int w, int h, char *p);
        virtual ~Bmp_image();
         int Witdh(){return witdh;}
          int Height(){return height;}
          char* Pixels(){return pixels;}
              char *pixels;


       // Bmp_image* load_image(const char *file_name);
    protected:
    private:

  void read32bit();
   short bits_per_pixels();
   int offset_data;
   int size;
    int witdh;
    int height;
};


     int toInt(const char* bytes);
     short toShort(const char* bytes);
     int readInt(ifstream &input);
     short readShort(ifstream &input);
     void read_header();


Bmp_image* load_bitmap(const char *file_name);



#endif // BMP_IMAGE_H
