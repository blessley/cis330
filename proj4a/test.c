#include <stdio.h>
#include<stdlib.h>

int main()
{
  char *solution = malloc(2*sizeof(char));
  int total = 23;
  *(solution + 0) = (total % 10) + 48; //'3'
  printf("%c\n", *solution);
  total = 25; 
  *(solution + 1) = (total % 10) + 48; // '5'
  printf("%c\n", *(solution+1));

}
