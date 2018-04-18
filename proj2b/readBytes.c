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

  unsigned int e = 1;
  char *c = (char*)&e;
  if (*c)    
    printf("Little endian\n");
  else
    printf("Big endian\n");

  //char buffer[2];
  //fread(buffer, sizeof(char), 2, inFile);
  //printf("%d %d\n", buffer[0], buffer[1]);

  FILE *outFile;
  outFile = fopen("output", "w");
  //fprintf(outFile, "Output\n");
 
  const int skip = w - 5; 
  int buffer[5];
  int i, j;
  for(i = 0; i < 5; i++)
  {
    fread(buffer, sizeof(int), 5, inFile);
    fprintf(outFile, "%d", buffer[0]);
    for(j = 1; j < 5; j++)
    {
      fprintf(outFile, "\n%d", buffer[j]);
    }
    fprintf(outFile, "\n");
    int pos = (int)ftell(inFile)/sizeof(int);
    fprintf(stdout, "pos: %d\n", pos);
    fseek(inFile, sizeof(int)*skip, SEEK_CUR);
  }
  fseek(inFile, 0, SEEK_END);
  long totalBytes = ftell(inFile);
  fprintf(stdout, "total bytes = %ld\n", totalBytes);
  fclose(inFile);
  fclose(outFile);

  return 0;
}
