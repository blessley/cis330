#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *inFile;
  inFile = fopen(argv[1], "rb");
  if (!inFile)
  {
    printf("Unable to open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  const int w = atoi(argv[2]);
  const int h = atoi(argv[3]);
  const int totalPixels = w*h;

  unsigned int i = 1;
  char *c = (char*)&i;
  if (*c)    
    printf("Little endian");
  else
    printf("Big endian");

  char buffer[2];
  fread(buffer, sizeof(char), 2, inFile);
  printf("%d %d\n", buffer[0], buffer[1]); 
  fclose(inFile);

  return 0;
}
