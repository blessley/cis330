#include <PNMwriter.h>

#include <image.h>

#include <stdio.h>
#include <iostream>

using std::cerr;
using std::endl;

void
PNMwriter::Write(const char *filename)
{
    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        cerr << "Unable to open file \"" << filename << "\" for WRITING" << endl;
        exit(EXIT_FAILURE);
    }

    if (input1 == NULL)
    {
        cerr << "No image to write!" << endl;
        exit(EXIT_FAILURE);
    }

   
    fprintf(f, "P6\n%d %d\n255\n", input1->GetWidth(), input1->GetHeight());
    fwrite(input1->GetBuffer(), sizeof(Pixel), 
           input1->GetWidth()*input1->GetHeight(), f);

    fclose(f);
}
