#include "source.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef PNMREADER330
#define PNMREADER330

class PNMreader : public Source
{
    public:
    char * f_name;

    public:
    PNMreader(char * filename);
    ~PNMreader();
    void Execute(void);
};

#endif
