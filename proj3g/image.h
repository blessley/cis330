#ifndef IMAGE_H
#define IMAGE_H

struct Pixel
{
    unsigned char r, g, b;
};

class Source;

class Image
{
  public:
                    Image();
    virtual        ~Image();

    void            ResetSize(int w, int h);
    void            Update() const;
    void            SetSource(Source *s) { source = s; };
    
    int             GetWidth()  const { return width;  };
    int             GetHeight() const { return height; };

    const Pixel    *GetPixel(int r, int c) const;
    void            SetPixel(int r, int c, const Pixel *);

    Pixel          *GetBuffer(void) { return buffer; };
    const Pixel    *GetBuffer(void) const { return buffer; };

  private:
    int             width, height;
    Pixel          *buffer;
    Source         *source;
};


#endif
