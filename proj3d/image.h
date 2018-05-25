/*	Author: John Nemeth
	Description: header file for image/pixel struct
	Sources: class material
*/
#ifndef IMAGE_H
#define IMAGE_H

#define CHAR_BUFFER 128

using namespace std;

struct Pixel
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};

class Image
{
	public:
		// constructor/destructors
		Image();
		Image(const Image &);			// copy constructor
		Image(int , int);			// parametrized constructor 
		virtual ~Image();			// virtual destructor

		void setWidth(int);
		void setHeight(int);
		void setMaxColor(int);
		void setMagicNum(char *);
		void setPBuffer(Pixel *);

		int getWidth();
		int getHeight();
		int getMaxColor();
		char * getMagicNum();
		Pixel * getPBuffer();

		const Image& operator=(const Image&); 	// assignment overloader (not used for proj3C/3D)

	private:
		int width;				// height and width by pixel
		int height;
		int maxColorVal;			// holds color depth
		char *magicNum;				// holds type of pnm
		Pixel *pBuffer;				// holds pixel RGB values
};
#endif
