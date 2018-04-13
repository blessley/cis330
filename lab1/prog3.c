#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  int X[3] = {1,2,3};
  int w = X[4];
  X[5] = 6;
  int q = X[-100];

  int *Y = malloc(sizeof(int) * 5);
  Y[0] = 1;
  Y[1] = 2;
  Y[2] = 3;
  int r = Y[4];
  if (r == 0)
    printf("BAD %d\n", r);
  Y[5] = 6;

}
