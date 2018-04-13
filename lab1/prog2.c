#include <stdio.h>
#include <stdlib.h>

int my_func(int *p)
{
  *(p+7) += 100;
  *(p+7) %= 200;
  return 7;
}

int main()
{
  int my_variable = 2;
  int *A = (int*)calloc(8, sizeof(int)); 
//{0,0,0,0,0,0,0,0};
  
  //A billion lines of code...

  my_variable <<= 35/27 + 1;
  printf("%d\n", my_variable);

  //Another billion lines of code...

  int x = A[my_variable];
  printf("%d\n", x);

  int y = A[A[my_func(A)]];

  free(A);

  return 0;
}
