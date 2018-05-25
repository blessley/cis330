#include "image.h"

#ifndef SOURCE330
#define SOURCE330

class Source
{
    protected: 
    Image img;

    public:
    virtual void Execute(void) = 0;
    Image * GetOutput(void);
};

#endif
