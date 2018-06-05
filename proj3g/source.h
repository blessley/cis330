#ifndef SOURCE_H
#define SOURCE_H

#include <image.h>

class Source
{
  public:
                   Source();

    virtual void   Update();
    virtual void   Execute() = 0;
    Image         *GetOutput();

  protected:
    Image          output;
};

#endif
