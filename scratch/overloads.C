#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

static int alloc = 0;
static int dealloc = 0;

class Image
{
  private:
    int width;
    int height;
    //Image(): width(0), height(0) {};
    /*
    Image (int width, int height)
    {
      this->width = width;
      this->height = height;

    }
    */
  public:
    Image() : width(0), height(0) {};
    Image(int w, int h) : width(w), height(h) {};
   
    int getWidth() const { return this->width; };
    int getHeight() const { return this->height; };
    void resize(int w, int h)
    {
      this->width = w;    
      this->height = h;
    };
};

/*
ostream& operator<<(ostream &out, const Image &img)
{
  out << "Image(" << img.getWidth() << "," 
      << img.getHeight() << ")";
  return out;
} 
*/

istream& operator>>(istream &in, Image &img)
{
  int w, h;
  in >> w;
  in >> h;
  img.resize(w, h);
  return in;
} 

void* operator new(size_t size)
{
  cout << size << " bytes allocated" << endl;
  alloc++;
  return malloc(size);
} 

void operator delete(void* ptr)
{
  dealloc++;
  free(ptr);
}


Image *img;

Image* GetOutput()
{
  return img;
{

int main()
{
  Image img;

  int *i;

  int j = 34;
  i = &j;

  cin >> img;
  //cout << img << endl;
  Image *imgArray = new Image[4];
  img.resize(10,10); 
  //cout << img << endl;
  //cout << "alloc = " << alloc << endl;
  //cout << "dealloc = " << dealloc << endl;

  ofstream outFile;
  outFile.open("out.txt");

  outFile << "Hello world\n";
  outFile.close();

  return 0;
}
