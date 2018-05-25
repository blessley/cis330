#include <iostream>
#include <image.h>


typedef struct
{
  unsigned char r;
  unsigned char g;
  unsigned char b;
} Pixel;


void invertRGB(Pixel *buff)
{
  


}



int main()
{
    Image img;    

    Pixel *buffer = new Pixel[img.width * img.height];

    invertRGB(buffer);

    for (int i = 0; i < img.width; i++)
      for (int j = 0; j < img.height; j++)
        std::cout <<   
    

  return 0;
}
