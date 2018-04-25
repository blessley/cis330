#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	unsigned char r, g, b;
} Pixel;

typedef struct
{
	int x, y;
	Pixel *data;
} Image;


static Image *ReadImage(char *filename)
{
    FILE *f = fopen(filename, "rb");
    Image *img = NULL;
    char magicNum[128];
    int  width, height, maxval;

    if (f == NULL)
    {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return NULL;
    }

    fscanf(f, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
    
    if (strcmp(magicNum, "P6") != 0)
    {
        fprintf(stderr, "Unable to read from file %s, because it is not a PNM file of type P6\n", filename);
        return NULL;
    }

    img = (Image *) malloc(sizeof(Image));
    img -> x = width;
    img -> y = height;
    img -> data = (Pixel*) malloc(img -> x * img -> y * sizeof(Pixel));

    fread(img -> data, sizeof(Pixel), width*height, f);
 
    fclose(f);
    return img;

}


void WriteImage(Image *img, char *filename)
{
    FILE *f = fopen(filename, "wb");

    if (f == NULL)
    {
        printf ("Unable to open '%s' for writing!\n", filename);
     /* better would be: "return -1" to indicate an error, 0 otherwise */
        exit(EXIT_FAILURE);
    }

    fprintf (f, "P6\n");
    fprintf (f, "%d %d\n", img->x, img->y);
    fprintf (f, "%d\n", 255);

    fwrite(img->data, sizeof(Pixel), img->x * img->y, f);
    fclose(f);
}

/*
//Image *
YellowDiagonal(Image *input)
{
}
 */

int main(int argc, char *argv[])
{
   FILE *input = NULL, *output = NULL;
   Image *image;
   
   if (argc != 3)
        {
                printf("WARNING: WRONG NUMBER OF ARGS!!!\n");
                exit(EXIT_FAILURE);
        }
   
   
   image = ReadImage(argv[1]);
   
   WriteImage(image, argv[2]);
}
