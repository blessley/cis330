#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int X[3] = {1,2,3};
  int w = X[4];
  X[5] = 6;
  int q = X[3];
  char *s = NULL;
  //printf("%c\n", *s); 
  //*s = 'h';
  char t[] = "hello world";
  int len = strlen(t);
  s = (char*) malloc(128);
  strcpy(s, argv[1]);
  s[1] = 'f';
  printf("%s\n", argv[1]);
  int *Y = (int*) malloc(sizeof(int)*5);
  Y[0] = 1;
  Y[1] = 2;
  Y[2] = 3;
  int r = Y[4];
  Y[4] = 6;
  int numBytes = sizeof(int)*5;
  int *Z = (int*) malloc(numBytes);
  memcpy(Y, Z, numBytes);
  free(Y);
  free(Z);
  free(s);  
}
