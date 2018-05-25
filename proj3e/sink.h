#ifndef SINK
#define SINK
#include <stdio.h>
#include <image.h>
class Sink{
   protected:
	Image *im1;
	Image *im2;
   public:	
		Sink(void);
	void SetInput(Image *image){im1 = image;};
	void SetInput2(Image *image){im2 = image;};
	Image *getIm1(void){return im1;};
	Image *getIm2(void){return im2;};
};
#endif
