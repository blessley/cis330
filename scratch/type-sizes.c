#include <stdio.h>
#include <limits.h>

int main()
{
  printf("Bits per byte: %u B\n", CHAR_BIT);
  printf("sizeof(short int): %zu B\n", sizeof(short int));
  printf("sizeof(float): %zu B\n", sizeof(float));

  return 0;
}
