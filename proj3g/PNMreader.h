#ifndef PNM_READER_H
#define PNM_READER_H

#include <source.h>

class PNMreader : public Source
{
  public:
                      PNMreader(const char *f);
    virtual          ~PNMreader();

    virtual void      Execute();

  protected:
    char             *filename;
};

#endif
