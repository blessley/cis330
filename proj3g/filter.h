#ifndef FILTER_H
#define FILTER_H

#include <source.h>
#include <sink.h>

class Filter : public Source, public Sink
{
  public:
    virtual     void Update();
    virtual     int  GetNumberOfInputs() = 0;
};

class SingleInputFilter : public Filter
{
  public:
    virtual     int GetNumberOfInputs() { return 1; };
};
class DoubleInputFilter : public Filter
{
  public:
    virtual     int GetNumberOfInputs() { return 2; };
};

class Mirror : public SingleInputFilter
{
  public:
    virtual void Execute();
};

class Grayscale : public SingleInputFilter
{
  public:
    virtual void Execute();
};

class Blur : public SingleInputFilter
{
  public:
    virtual void Execute();
};

class Subtract : public DoubleInputFilter
{
  public:
    virtual void Execute();
};

class Shrinker : public SingleInputFilter
{
  public:
    virtual void Execute();
};

class Rotate : public SingleInputFilter
{
  public:
    virtual void Execute();
};

class LRCombine : public DoubleInputFilter
{
  public:
    virtual void Execute();
};

class TBCombine : public DoubleInputFilter
{
  public:
    virtual void Execute();
};

class Blender : public DoubleInputFilter
{
  public:
                 Blender() { factor = 0.; };
    void         SetFactor(double f) { factor = f; };
    virtual void Execute();

  protected:
    double       factor;
};

class Color : public Source
{
  public:
                          Color(int, int, unsigned char, unsigned char, unsigned char);
    virtual void          Execute();

  protected:
    int   width, height;
    Pixel color;
};

class CheckSum : public Sink
{
  public:
    void         OutputCheckSum(const char *);
}; 

#endif
