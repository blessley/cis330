#include <PNMreader.h>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using std::cerr;
using std::endl;

PNMreader::PNMreader(const char *f)
{
    filename = new char[strlen(f)+1];
    strcpy(filename, f);
}

PNMreader::~PNMreader()
{
    delete [] filename;
}

void
PNMreader::Execute()
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        cerr << "Unable to open file \"" << filename << "\"" << endl;
        exit(EXIT_FAILURE);
    }

    char format[128];
    int maxval;
    int w, h;
    fscanf(f, "%s\n%d %d\n%d\n", format, &w, &h, &maxval);
    //cerr << "W = " << w << ", H = " << h << endl;

    output.ResetSize(w, h);
    Pixel *buffer = output.GetBuffer();
    fread(buffer, sizeof(Pixel), w*h, f);

    fclose(f);
}
