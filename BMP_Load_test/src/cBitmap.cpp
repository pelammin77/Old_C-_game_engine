#include "cBitmap.h"

cBitmap::cBitmap()
{
      mBitmap	= NULL;
	mWidth	= 0;
	mHeight	= 0;
	mStride	= 0;
	mType	= 0;

	GdiFlush();
}

cBitmap::~cBitmap()
{
    FreeImage();
}

void cBitmap::FreeImage()
{

    	if(mBitmap)
		DeleteObject(mBitmap);

	mBitmap	= NULL;
	mWidth	= 0;
	mHeight	= 0;
	mStride = 0;
	mType	= 0;
	pixels	= NULL;

}

bool cBitmap::SizeImage(int w, int h, int channels)
{
    	FreeImage();
	HDC tmpDC = CreateCompatibleDC(NULL);
	if(!tmpDC){
		MessageBox(NULL, "CreateCompatibleDC() failed!", "Error SizeImg()", MB_OK);
		return false;
	}

    mWidth	= w;
	mHeight	= h;
	mType	= channels;

	mStride = mWidth * mType;
	while((mStride % 4) != 0)
		mStride++;

	BITMAPINFO bInfo ;


	bInfo.bmiHeader.biSize          = sizeof(BITMAPINFOHEADER);
	bInfo.bmiHeader.biWidth			= mWidth;
	bInfo.bmiHeader.biHeight		= mHeight;
	bInfo.bmiHeader.biPlanes		= 1;			// This will always be 1
	bInfo.bmiHeader.biBitCount		= mType * 8;	// 3 channels = 24, 4 = 32
	bInfo.bmiHeader.biCompression	= BI_RGB;		// No compression
	bInfo.bmiHeader.biClrUsed		= 0;			// Always 0 when working with 24/32 bit bmps



	mBitmap = CreateDIBSection(tmpDC, &bInfo, DIB_RGB_COLORS, (void**)&pixels, 0, 0);

	DeleteDC(tmpDC);
	if(!mBitmap){
		MessageBox(NULL, "CreateDIBSection() failed!", "Error SizeImg()", MB_OK);
		return false;
	}


 return true;

}

bool cBitmap::LoadBMP(const char *filename)
{
  	FreeImage();
	if(!filename){
		MessageBox(NULL, "Bad file name!", "Error LoadBMP()", MB_OK);
		return false;
	}


	FILE  *img = NULL;
	img = fopen(filename, "rb");	// Notice we read the file in  byte by byte. 'rb' means Read Byte mode.

	if(!img){
		MessageBox(NULL, "fopen() failed!", "Error LoadBMP()", MB_OK);
		return false;
	}

	BITMAPFILEHEADER bHeader;

	if(!fread(&bHeader, sizeof bHeader, 1, img)){
		MessageBox(NULL, "fread() [BITMAPFILEHEADER] failed!", "Error LoadBMP()", MB_OK);
		return false;
	}

	if(memcmp(&bHeader.bfType, "BM", 2)){
		MessageBox(NULL, "memcmp() detected false file type!", "Error LoadBMP()", MB_OK);
		fclose(img); // Close the file since it is the wrong filetype.
		return false;
	}

		BITMAPINFOHEADER bInfo;

	// Read in the info for the bitmap.
	if(!fread(&bInfo, sizeof(BITMAPINFOHEADER), 1, img))
	{
		MessageBox(NULL, "fread() [BITMAPINFOHEADER] failed!", "Error LoadBMP()", MB_OK);
		fclose(img);
		return false;
	}

	if((bInfo.biBitCount != 24) && (bInfo.biBitCount != 32)){
		/*
			Here, we checked if the image was 24 or 32 bits. If it is neither, then we just return false after
				closing the file. This loader is currently unable to load monochrome, or 8 bit bmp images. We
				will simply stick to 24 or 32.
		*/
		MessageBox(NULL, "Not a valid 24 | 32 bit image type!", "Error LoadBMP()", MB_OK);
		fclose(img);
		return false;
	}

		if(!SizeImage(bInfo.biWidth, bInfo.biHeight, bInfo.biBitCount/8)){
		MessageBox(NULL, "Size() failed!", "Error LoadBMP()", MB_OK);
		fclose(img);
		return false;
	}

       	unsigned int bytesPerLine	= mWidth * mType;			// Get the number of bytes per line
//	        unsigned int padCount	= mStride - bytesPerLine;	// Get the amount of padding involved.

	// Loop through and read the data in
	for(int i=0; i<mHeight; i++){
		/*
			i is the line number in the image we are on. In this case, i
				will start at 0 being the top of the file. From each line, we need
				to relocate our position
		*/
		unsigned char* pos = GetPixels(i);			// Relocate our position

		/*
			Read in the image data
		*/
		if(!fread(pos, bytesPerLine, 1, img)){
			MessageBox(NULL, "fread() at ImageData failed!", "Error LoadBMP()", MB_OK);
			fclose(img);
			return false;
		}

		/*
			Skip over padding, remember that fseek returns 0 on succes, and negative values
				for errors.
		*/
		if(fseek(img, 0, SEEK_CUR)){
			MessageBox(NULL, "fread() at padding failed!", "Error LoadBMP()", MB_OK);
			fclose(img);
			return false;
		}
	}



  fclose(img);
  return true;
}

unsigned char* cBitmap::GetPixels(int i)
{
  	return (pixels + mStride * i);
}
