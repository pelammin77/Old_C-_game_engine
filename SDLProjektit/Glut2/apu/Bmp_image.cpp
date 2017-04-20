#include "Bmp_image.h"
#include <fstream>
#include <assert.h>
using namespace std;


namespace
{



    template<class T>
	class auto_array {
		private:
			T* array;
			mutable bool isReleased;
		public:
			explicit auto_array(T* array_ = NULL) :
				array(array_), isReleased(false) {
			}

			auto_array(const auto_array<T> &aarray) {
				array = aarray.array;
				isReleased = aarray.isReleased;
				aarray.isReleased = true;
			}

			~auto_array() {
				if (!isReleased && array != NULL) {
					delete[] array;
				}
			}

			T* get() const {

				return array;
			}

			T &operator*() const {
				return *array;
			}

			void operator=(const auto_array<T> &aarray) {
				if (!isReleased && array != NULL) {
					delete[] array;
				}
				array = aarray.array;
				isReleased = aarray.isReleased;
				aarray.isReleased = true;
			}

			T* operator->() const {
				return array;
			}

			T* release() {
				isReleased = true;
				return array;
			}

			void reset(T* array_ = NULL) {
				if (!isReleased && array != NULL) {
					delete[] array;
				}
				array = array_;
			}

			T* operator+(int i) {
				return array + i;
			}

			T &operator[](int i) {
				return array[i];
			}
	};
}






Bmp_image::Bmp_image(int w, int h, char *p)
{
    witdh = w;
    height = h;
    pixels = p;

  //  delete [] p;
}

Bmp_image::~Bmp_image()
{
    delete [] pixels;
}



 int readInt(ifstream &input)
 {

        char buffer[4];
		input.read(buffer, 4);
		return toInt(buffer);


 }

 short readShort(ifstream &input)
 {

char buffer[4];
		input.read(buffer, 4);
		return toShort(buffer);


 }


int toInt(const char *bytes)
{

    return (int)(((unsigned char)bytes[3] << 24) |
					 ((unsigned char)bytes[2] << 16) |
					 ((unsigned char)bytes[1] << 8) |
					 (unsigned char)bytes[0]);

}


short toShort(const char *bytes)
{
    return (short)(((unsigned char)bytes[1] << 8) |
					   (unsigned char)bytes[0]);

}


Bmp_image* load_bitmap(const char *file_name)
{

    ifstream input;
    input.open(file_name, ifstream::binary);
    assert(!input.fail() || !"Can not open the file");
    char buffer[2];
	input.read(buffer, 2);
	assert(buffer[0] == 'B' && buffer[1] == 'M' || !"Not a bitmap file");
	input.ignore(8);
    int dataOffset = readInt(input);
    int header_size = readInt(input);
     int w, h ;
      short bits_per_pixel;
    //read header
	switch(header_size) {
		case 40:
			//V3
			w = readInt(input);
			h = readInt(input);
			input.ignore(2);
			 bits_per_pixel = readShort(input);
			//if(bits_per_pixel!= 24 ) return NULL;
			assert(readShort(input) == 0 || !"Image is compressed");
			break;
		case 12:
			//OS/2 V1
			w = readShort(input);
			h = readShort(input);
			input.ignore(2);
             bits_per_pixel = readShort(input);
			break;
		case 64:
			//OS/2 V2
			assert(!"Can't load OS/2 V2 bitmaps");
			break;
		case 108:
			//Windows V4
			assert(!"Can't load Windows V4 bitmaps");
			break;
		case 124:
			//Windows V5
			assert(!"Can't load Windows V5 bitmaps");
			break;
		default:
			assert(!"Unknown bitmap format");
	}

// read data
//int bytesPerRow = ((w * 3 + 3) / 4) * 4 - (w * 3 % 4);
//int bytesPerRow = ((bits_per_pixel * w)/32)*4;
//	int size = bytesPerRow * h;
//	auto_array<char> pixels(new char[size]);
//	input.seekg(dataOffset, ios_base::beg);
//	input.read(pixels.get(), size);
//
//	//Get the data into the right format
//	auto_array<char> pixels2(new char[w * h * 3]);
//	for(int y = 0; y < h; y++) {
//		for(int x = 0; x < w; x++) {
//			for(int c = 0; c < 3; c++) {
//				pixels2[3  * (w * y + x) + c] =
//					pixels[bytesPerRow * y + 3 * x + (2 - c)];
//					//input.ignore(1);
//			}
//		}
//}


 char skip;
auto_array<char> pixels(new char[w*h*3]);
input.seekg(dataOffset, ios_base::beg);
 for (int i = 0; i < w * h; ++i)
 {
     pixels[(i * 3) + 2] = input.get();
      pixels[(i * 3) + 1] = input.get();
       pixels[(i * 3) + 0] = input.get();

      if(bits_per_pixel == 32) skip = input.get();
 }



input.close();
	return new Bmp_image(w,h,pixels.release());


}


void Bmp_image::read32bit()
{

}




//Bmp_image load_bitmap(const char* file_name)

