#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *outFile;
  outFile = fopen(argv[1], "wb");
  if (!outFile)
  {
    printf("Unable to open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  const int w = atoi(argv[2]);
  const int h = atoi(argv[3]);
  const int totalPixels = w*h;

  //2D image with 0-index at bottom left corner
  //Indexing proceeds left-to-right, bottom-to-top
  //Last index (w*h - 1) is top left and first value written
  int i, j, id = totalPixels-1; 
  for (i = 0; i < h; i++)
  {
    for (j = 0; j < w; j++)
    {
      fwrite(&id, sizeof(int), 1, outFile);
      id--;
    }
  } 
  fclose(outFile);
  return 0;
}
