#include <filter.h>

#include <iostream>
#include <stdlib.h>

#include <logging.h>

using std::cerr;
using std::endl;

void
Filter::Update()
{
   if (input1 == NULL)
   {
       char msg[1024];
       sprintf(msg, "no input1");
       DataFlowException e("filter", msg);
       throw e;
   }
   input1->Update();
   if (GetNumberOfInputs() == 2)
   {
       if (input2 == NULL)
       {
           char msg[1024];
           sprintf(msg, "no input2");
           DataFlowException e("filter", msg);
           throw e;
       }
       input2->Update();
   }
   Execute();
}

/*
width = 4
height = 3
# of columns = width
# of rows = height

a b c d
e f g h
i j k l
 */

void
Shrinker::Execute()
{
    int out_width  = input1->GetWidth()/2;
    int out_height = input1->GetHeight()/2;
    output.ResetSize(out_width, out_height);
    for (int r = 0 ; r < out_height ; r++)
        for (int c = 0 ; c < out_width ; c++)
        {
            output.SetPixel(r, c, input1->GetPixel(2*r, 2*c));
        }
}

void Mirror::Execute()
{
    int out_width = input1->GetWidth();
    int out_height = input1->GetHeight();
    output.ResetSize(out_width, out_height);
    for (int r = 0 ; r < input1->GetHeight() ; r++)
        for (int c = 0 ; c < input1->GetWidth() ; c++)
        {
            output.SetPixel(r, c, input1->GetPixel(r, input1->GetWidth()-c-1));
        }
}

void LRCombine::Execute()
{
    int out_width = input1->GetWidth() + input2->GetWidth();
    int out_height = input1->GetHeight();
    if (input1->GetHeight() != input2->GetHeight())
    {
       char msg[1024];
       sprintf(msg, "no input1");
       DataFlowException e("LRcombine", msg);
       throw e;
    }

    output.ResetSize(out_width, out_height);

    bool doMethod1 = true;
    if (doMethod1)
    {
        for (int r = 0 ; r < input1->GetHeight() ; r++)
            for (int c = 0 ; c < input1->GetWidth() ; c++)
            {
                output.SetPixel(r, c, input1->GetPixel(r, c));
            }
        for (int r = 0 ; r < input2->GetHeight() ; r++)
            for (int c = 0 ; c < input2->GetWidth() ; c++)
            {
                output.SetPixel(r, c+input1->GetWidth(), input2->GetPixel(r, c));
            }
    }
    else
    {
        for (int r = 0 ; r < output.GetHeight() ; r++)
            for (int c = 0 ; c < output.GetWidth() ; c++)
            {
                if (c <= input1->GetWidth())
                    output.SetPixel(r, c, input1->GetPixel(r, c));
                else
                    output.SetPixel(r, c, input2->GetPixel(r, c-input1->GetWidth()));
            }
     
    }
}

void TBCombine::Execute()
{
    if (input1->GetWidth() != input2->GetWidth())
    {
        char msg[1024];
        sprintf(msg, "width mismatch");
        DataFlowException e("TBcombine", msg);
        throw e;
    }
    int out_width = input1->GetWidth();
    int out_height = input1->GetHeight() + input2->GetHeight();

    output.ResetSize(out_width, out_height);

    for (int r = 0 ; r < input1->GetHeight() ; r++)
        for (int c = 0 ; c < input1->GetWidth() ; c++)
        {
            output.SetPixel(r, c, input1->GetPixel(r, c));
        }
    for (int r = 0 ; r < input2->GetHeight() ; r++)
        for (int c = 0 ; c < input2->GetWidth() ; c++)
        {
            output.SetPixel(r+input1->GetHeight(), c, input2->GetPixel(r, c));
        }
}

void Blender::Execute()
{
    if (input1->GetWidth() != input2->GetWidth() || input1->GetHeight() != input2->GetHeight())
    {
        char msg[1024];
        sprintf(msg, "size mismatch");
        DataFlowException e("Blender", msg);
        throw e;
    }

    if (factor < 0 || factor > 1.0)
    {
        char msg[1024];
        sprintf(msg, "invalid factor");
        DataFlowException e("Blender", msg);
        throw e;
    }

    int out_width = input1->GetWidth();
    int out_height = input1->GetHeight();

    output.ResetSize(out_width, out_height);

    for (int r = 0 ; r < input1->GetHeight() ; r++)
        for (int c = 0 ; c < input1->GetWidth() ; c++)
        {
            const Pixel *in1_p = input1->GetPixel(r, c);
            const Pixel *in2_p = input2->GetPixel(r, c);
            Pixel        out_p;

            out_p.r = factor*in1_p->r + (1.0-factor)*in2_p->r;
            out_p.g = factor*in1_p->g + (1.0-factor)*in2_p->g;
            out_p.b = factor*in1_p->b + (1.0-factor)*in2_p->b;
            output.SetPixel(r, c, &out_p);
        }
}

void
Rotate::Execute()
{
    int in1_width  = input1->GetWidth();
    int in1_height = input1->GetHeight();
    int out_width  = in1_height;
    int out_height = in1_width;
    output.ResetSize(out_width, out_height);
    for (int row = 0 ; row < in1_height ; row++)
        for (int col = 0 ; col < in1_width ; col++)
        {
            int output_row = col;
            int output_col = out_width - row - 1;
            output.SetPixel(output_row, output_col,
                            input1->GetPixel(row, col));
        }
}

void Subtract::Execute()
{
    if (input1->GetWidth() != input2->GetWidth() || input1->GetHeight() != input2->GetHeight())
    {
        char msg[1024];
        sprintf(msg, "size mismatch");
        DataFlowException e("Subtract", msg);
        throw e;
    }

    int out_width = input1->GetWidth();
    int out_height = input1->GetHeight();

    output.ResetSize(out_width, out_height);

    for (int r = 0 ; r < input1->GetHeight() ; r++)
        for (int c = 0 ; c < input1->GetWidth() ; c++)
        {
            const Pixel *in1_p = input1->GetPixel(r, c);
            const Pixel *in2_p = input2->GetPixel(r, c);
            Pixel        out_p;

            out_p.r = ((in1_p->r > in2_p->r) ? (in1_p->r - in2_p->r) : 0);
            out_p.g = ((in1_p->g > in2_p->g) ? (in1_p->g - in2_p->g) : 0);
            out_p.b = ((in1_p->b > in2_p->b) ? (in1_p->b - in2_p->b) : 0);
            output.SetPixel(r, c, &out_p);
        }
}


void Grayscale::Execute()
{
    int out_width = input1->GetWidth();
    int out_height = input1->GetHeight();

    output.ResetSize(out_width, out_height);

    for (int r = 0 ; r < input1->GetHeight() ; r++)
        for (int c = 0 ; c < input1->GetWidth() ; c++)
        {
            const Pixel *in1_p = input1->GetPixel(r, c);
            Pixel        out_p;

            unsigned char gray = in1_p->r/5 + in1_p->g/2 + in1_p->b/4;
            out_p.r = gray;
            out_p.g = gray;
            out_p.b = gray;
            output.SetPixel(r, c, &out_p);
        }
}

void Blur::Execute()
{
    int out_width = input1->GetWidth();
    int out_height = input1->GetHeight();

    output.ResetSize(out_width, out_height);

    for (int r = 0 ; r < input1->GetHeight() ; r++)
        for (int c = 0 ; c < input1->GetWidth() ; c++)
        {
            if (r == 0 || r == input1->GetHeight()-1 || c == 0 || c == input1->GetWidth()-1)
            {
                const Pixel *in1_p = input1->GetPixel(r, c);
                output.SetPixel(r, c, in1_p);
                continue;
            }

            const Pixel *in_ul = input1->GetPixel(r-1, c-1);
            const Pixel *in_up = input1->GetPixel(r-1, c);
            const Pixel *in_ur = input1->GetPixel(r-1, c+1);
            const Pixel *left  = input1->GetPixel(r, c-1);
            const Pixel *right = input1->GetPixel(r, c+1);
            const Pixel *in_ll = input1->GetPixel(r+1, c-1);
            const Pixel *in_down = input1->GetPixel(r+1, c);
            const Pixel *in_lr = input1->GetPixel(r+1, c+1);

            Pixel out_p;
            out_p.r = in_ul->r/8 + in_up->r/8 + in_ur->r/8 + left->r/8
                    + right->r/8 + in_ll->r/8 + in_down->r/8 + in_lr->r/8;
            out_p.g = in_ul->g/8 + in_up->g/8 + in_ur->g/8 + left->g/8
                    + right->g/8 + in_ll->g/8 + in_down->g/8 + in_lr->g/8;
            out_p.b = in_ul->b/8 + in_up->b/8 + in_ur->b/8 + left->b/8
                    + right->b/8 + in_ll->b/8 + in_down->b/8 + in_lr->b/8;
            output.SetPixel(r, c, &out_p);
        }
}

Color::Color(int w, int h, unsigned char r, unsigned char g, unsigned char b)
{
    if (w < 0 || h < 0)
    {
        char msg[1024];
        sprintf(msg, "invalid size");
        DataFlowException e("Color", msg);
        throw e;
    }
    color.r = r;
    color.g = g;
    color.b = b;
    width   = w;
    height  = h;
}

void
Color::Execute()
{
    output.ResetSize(width, height);

    for (int r = 0 ; r < height ; r++)
        for (int c = 0 ; c < width ; c++)
        {
            output.SetPixel(r, c, &color);
        }
}

void
CheckSum::OutputCheckSum(const char *filename)
{
    unsigned char r_sum = 0;
    unsigned char g_sum = 0;
    unsigned char b_sum = 0;
    for (int r = 0 ; r < input1->GetHeight() ; r++)
        for (int c = 0 ; c < input1->GetWidth() ; c++)
        {
            const Pixel *p = input1->GetPixel(r, c);
            r_sum += p->r;
            g_sum += p->g;
            b_sum += p->b;
        }
    
    FILE *f = fopen(filename, "w");
    fprintf(f, "CHECKSUM: %d, %d, %d\n", r_sum, g_sum, b_sum);
}
