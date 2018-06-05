#include <source.h>

#include <iostream>

using std::cerr;
using std::endl;


Source::Source()
{
    output.SetSource(this);
}

void
Source::Update()
{
    Execute();
}

Image *
Source::GetOutput()
{
    return &output;
}
