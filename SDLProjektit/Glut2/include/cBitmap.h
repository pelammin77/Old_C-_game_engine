#ifndef CBITMAP_H
#define CBITMAP_H


#include <windows.h>
#include <stdio.h>


class cBitmap
{
    public:
        cBitmap();
        virtual ~cBitmap();
        bool LoadBMP(const char* filename);
        const int GetWidth() const  { return mWidth; }
        const int GetHeight()const { return mHeight;}
        const int GetType() const  { return mType;  }
	    const int GetStride()const { return mStride;}

	unsigned char* GetPixels(int i);
    protected:
    private:
      int mWidth;
      int mHeight;
      int mType;
      int mStride;
      HBITMAP mBitmap;
	  unsigned char *pixels;

//methods
    private:
    	void FreeImage();
    	bool SizeImage(int w, int h, int channels);



};

#endif // CBITMAP_H
