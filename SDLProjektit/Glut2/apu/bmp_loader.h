#ifndef BMP_LOADER_H_INCLUDED
#define BMP_LOADER_H_INCLUDED

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* OpenGL texture info */
struct gl_texture_t
{
  GLsizei width;
  GLsizei height;

  GLenum format;
  GLint	internalFormat;
  GLuint id;

  GLubyte *texels;
};

#pragma pack(push, 2)
/* Bitmap file header */
struct bmp_file_header_t
{
  unsigned char bfType[2];      /* magic number "BM" */
  unsigned int bfSize;          /* file size */
  unsigned short bfReserved1;
  unsigned short bfReserved2;
  unsigned int bfOffBits;       /* offset to image data */
};
#pragma pack(pop)

/* Bitmap info header */
struct bmp_info_header_t
{
  unsigned int biSize;          /* size of bitmap info header */
  int biWidth;                  /* image with */
  int biHeight;                 /* image height */
  unsigned short biPlanes;      /* must be equal to 1 */
  unsigned short biBitCount;    /* bits per pixels */
  unsigned int biCompression;   /* compression type */
  unsigned int biSizeImage;     /* size of pixel data */
  int biXPelsPerMeter;          /* pixels per meter on x-axis */
  int biYPelsPerMeter;          /* pixels per meter on y-axis */
  unsigned int biClrUsed;       /* number of used colors */
  unsigned int biClrImportant;  /* number of important colors */
};

/* Bitmap core header */
struct bmp_core_header_t
{
  unsigned int bcSize;           /* size of bitmap core header */
  unsigned short bcWidth;        /* image with */
  unsigned short bcHeight;       /* image height */
  unsigned short bcPlanes;       /* must be equal to 1 */
  unsigned short bcBitCount;     /* bits per pixel */
};

/* Bitmap core info */
struct bmp_core_info_t
{
  struct bmp_core_header_t bmciHeader;
  unsigned char bmciColors[3];
};

/* OS-style type */
enum os_type_e
  {
    BMP_WIN,
    BMP_OS2,
  };

enum compression_type_e
  {
    /* BMP compression type constants */
    BI_RGB          = 0,
    BI_RLE8         = 1,
    BI_RLE4         = 2,
    BI_BITFIELDS    = 3,

    /* RLE byte type constants */
    RLE_COMMAND     = 0,
    RLE_ENDOFLINE   = 0,
    RLE_ENDOFBITMAP = 1,
    RLE_DELTA       = 2,
  };

/* Texture id for the demo */
GLuint texId = 0;




static void
ReadBMP1bit (FILE *fp, const GLubyte *colormap,
	     enum os_type_e os_type, struct gl_texture_t *texinfo);



static void
ReadBMP4bits (FILE *fp, const GLubyte *colormap,
	      enum os_type_e os_type, struct gl_texture_t *texinfo) ;



static void
ReadBMP8bits (FILE *fp, const GLubyte *colormap,
	      enum os_type_e os_type, struct gl_texture_t *texinfo);




static void
ReadBMP24bits (FILE *fp, struct gl_texture_t *texinfo);





static void
ReadBMP32bits (FILE *fp, struct gl_texture_t *texinfo) ;




static void
ReadBMP8bitsRLE (FILE *fp, const GLubyte *colormap,
		 struct gl_texture_t *texinfo);



static void
ReadBMP4bitsRLE (FILE *fp, const GLubyte *colormap,
		 struct gl_texture_t *texinfo);


static struct gl_texture_t *
ReadBMPFile (const char *filename);

GLuint
loadBMPTexture (const char *filename);




#endif // BMP_LOADER_H_INCLUDED
