#include <stdio.h>
int main()
{
	int ch = getc(stdin);
	while (ch != EOF)
	{
		printf("%c%c", ch, ch);
		ch = getc(stdin);
	}
}
