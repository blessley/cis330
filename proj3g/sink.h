#ifndef SINK_H
#define SINK_H

class Image;

class Sink
{
  public:
                    Sink();
  
    void            SetInput(const Image *);
    void            SetInput2(const Image *);

  protected:
    const Image    *input1;
    const Image    *input2;
};

#endif
