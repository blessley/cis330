#include <sink.h>

#include <stdlib.h>

Sink::Sink()
{
    input1 = NULL;
    input2 = NULL;
}


void
Sink::SetInput(const Image *i)
{
    input1 = i;
}


void
Sink::SetInput2(const Image *i)
{
    input2 = i;
}

