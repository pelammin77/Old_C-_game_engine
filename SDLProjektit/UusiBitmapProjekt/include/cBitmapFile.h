#ifndef CBITMAPFILE_H
#define CBITMAPFILE_H
#include<stdio.h>
#include<gl\GL.h>

struct tBmpHeader
{
  unsigned char BMP_file_type;  //BM
  unsigned int BMP_file_size;
  unsigned short BMP_file_reserved1;
  unsigned short BMP_file_reserved2;
  unsigned int BMP_file_offset_bits;



};

struct tBmpInfoHeader
{
  unsigned int info_header_size;
  int info_header_width;
  int info_header_height;
  unsigned short info_header_planes;
  unsigned short info_header_bits_per_pixels;
  unsigned int info_header_coomperssion;
  unsigned int info_header_size_image;
  int info_header_pixels_per_meter_X;
  int info_header_pixels_per_meter_Y;
  unsigned int  info_header_color_used;
  unsigned int info_header_count_import_colors;


};


struct tBmpCoreHeader
{
 unsigned int core_header_size;
 unsigned short core_width;
 unsigned short core_height;
 unsigned short planes;
 unsigned short core_bits_per_pixels;




};

struct tBmpCoreInfoHeader
{

  tBmpCoreHeader core_header;

  char core_colors[3];

};


enum eOS_type
{
   WIN_BMP,
   OS2_BMP,
};


 enum eCompression_Type
 {

RGB              =  0,
RLE8             =  1,
RLE4             =  2,
BITTFIELDS       =  3,

RLE_COMMAND       =  0,
RLE_ENDOFLINE     =  0,
RLE_ENDOFBITMAP   =  1,
RLE_DELTA         =  2,

 };




class cBitmapFile
{
    public:
        cBitmapFile();
        virtual ~cBitmapFile();
        bool load_file( const char* file_name);
    protected:

    private:
        tBmpHeader header;
        tBmpInfoHeader info_header;

         tBmpCoreHeader core_header;
         tBmpCoreInfoHeader core_info_header;

        int width;
        int height;
        GLubyte* data;
        GLubyte* color_map;
        FILE *f;
        eOS_type system_type;


    private:

    void read24bit_file();
    void read32bit_file();




};





#endif // CBITMAPFILE_H
