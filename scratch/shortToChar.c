#include <stdio.h>


int main()
{

    short h1 = 256*84 + 74;

    short h2 = (84<<8) + 74;

    printf("H1 is %d, h2 is %d\n", h1, h2);

    // Byte 0: 0101 0100 = 84 = 'T'

    // Byte 1: 0100 1010 = 74 = 'J'

    // 256: 2^8 84*256 : 01010100 0000 0000

    // h: 0101 0100 0100 1010

    printf("Size of short is %lu\n", sizeof(short));

    FILE *f = fopen("output", "w");

    fwrite(&h1, sizeof(short), 1, f);

    fclose(f);

    FILE *f2 = fopen("output", "r");

    char two_chars[2];

    fread(two_chars, sizeof(char), 2, f2);

    printf("Char 1 is %c, char 2 is %c\n", two_chars[0], two_chars[1]);

    fclose(f2);

    return 0;
}
