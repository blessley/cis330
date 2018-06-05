#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int X[3] = {1,2,3};
  int w = X[4];
  X[5] = 6;
  int q = X[-100];
  char *s = NULL;
  printf("%c\n", *s); 
  *s = 'h';
  char t[] = "hello world";
  int len = strlen(t);
  strcpy(s, argv[1]);
  int *Y = (int*) malloc(sizeof(int)*5);
  Y[0] = 1;
  Y[1] = 2;
  Y[2] = 3;
  int r = Y[4];
  Y[5] = 6;
  int numBytes = sizeof(int)*INT_MAX;
  int *Z = (int*) malloc(numBytes);
  memcpy(Y, Z, numBytes);
  free(Y);

  return 0;
}
