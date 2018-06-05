#include <image.h>

#include <iostream>
#include <source.h>

using std::cerr;
using std::endl;

Image::Image()
{
    width  = 0;
    height = 0;
    source = NULL;
    buffer = NULL;
}

Image::~Image()
{
    if (buffer != NULL)
        delete [] buffer;
}

void 
Image::Update() const
{
    if (source == NULL)
    {
        cerr << "CANNOT UPDATE IMAGE ... NO SOURCE" << endl;
        exit(EXIT_FAILURE);
    }
    source->Update();
}
void 
Image::ResetSize(int w, int h)
{
    if (buffer != NULL)
        delete [] buffer;
    width  = w;
    height = h;
    buffer = new Pixel[width*height];
}

/*
0 1 2 3
4 5 X 7 << X: row == 1, column == 2
8 9 10 11
 */

const Pixel *
Image::GetPixel(int row, int column) const
{
    if (row < 0 || row >= height)
    {
        abort();
        cerr << "BAD ROW FOR GET PIXEL, row = " << row << ", height = " << height << endl;
        exit(EXIT_FAILURE);
    }
    if (column < 0 || column >= width)
    {
        abort();
        cerr << "BAD COLUMN FOR GET PIXEL, column = " << column << ", width = " << width << endl;
        exit(EXIT_FAILURE);
    }

    int index = row*width + column;
    return buffer+index;
}

void
Image::SetPixel(int row, int column, const Pixel *p)
{
    if (row < 0 || row >= height)
    {
        abort();
        cerr << "BAD ROW FOR GET PIXEL, row = " << row << ", height = " << height << endl;
        exit(EXIT_FAILURE);
    }
    if (column < 0 || column >= width)
    {
        abort();
        cerr << "BAD COLUMN FOR GET PIXEL, column = " << column << ", width = " << width << endl;
        exit(EXIT_FAILURE);
    }

    int index = row*width + column;
    buffer[index].r = p->r;
    buffer[index].g = p->g;
    buffer[index].b = p->b;
}
