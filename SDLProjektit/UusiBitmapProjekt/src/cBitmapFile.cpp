#include "cBitmapFile.h"

cBitmapFile::cBitmapFile()
{
    //ctor
}

cBitmapFile::~cBitmapFile()
{
    //dtor
}


   bool cBitmapFile::load_file( const char* file_name)
   {

       fpos_t bmp_pos;
       f = fopen(file_name,"rb");
       if(!f) return NULL ;

     fclose(f);
       return true;
   }




void cBitmapFile::read24bit_file()
{
    for(int i=0; i<width*height; ++i)
    {
        data[(i * 3) + 2]=(GLubyte) fgetc(f);
        data[(i * 3) + 1]=(GLubyte) fgetc(f);
        data[(i * 3) + 0]=(GLubyte) fgetc(f);
    }


}



void cBitmapFile::read32bit_file()
{
      GLubyte skip;

     for(int i=0; i<width * height; ++i)
    {
        data[(i * 3) + 2]=(GLubyte) fgetc(f);
        data[(i * 3) + 1]=(GLubyte) fgetc(f);
        data[(i * 3) + 0]=(GLubyte) fgetc(f);

        // skip last byte
        skip = (GLubyte) fgetc(f);
    }


}
