#ifndef IMAGE
#define IMAGE
#include <source.h>
class Pixel{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	
   public:	
	unsigned char getR(){return r;}
	unsigned char getB(){return b;}
	unsigned char getG(){return g;}

	void setR(unsigned char red){r = red;}
	void setB(unsigned char blue){b = blue;}
	void setG(unsigned char green){g = green;}
};

class Image{
	Pixel *pixels;
	int w;
	int h;
	Source *upPipe;
  public:
		Image(void);
		Image(int width, int height);
		Image(Image &toCopy);
		virtual ~Image(void);
	Pixel *getPixels(){return pixels;}
	int    getW(){return w;}
	int    getH(){return h;}
	void setPixels(Pixel *p){pixels = p;}
	void setW(int width){w = width;}
	void setH(int height){h = height;}
	void setUP(Source *f){upPipe = f;}
	Source * getUP(){return upPipe;}

	void Update();
	void ResetSize(int width, int height);

};
#endif
