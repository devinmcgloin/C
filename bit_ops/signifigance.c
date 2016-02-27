
#include <stdio.h>

/*(0x0000007b)(0x00)(0x7b) */
/*(0xffffff85)(0xff)(0x85) */
/*(0x07b00000)(0x07)(0x00)*/

int most(int x);
int least(int x);

int main()
{
    int a = 0x0000007b;
    int b = 0xffffff85;
    int c = 0x07b00000;
    printf("a=%x\n", a);
    printf("b=%x\n", b);
    printf("c=%x\n", c);
    /*printf("b >> sizeof(int)=%x\n", b >> sizeof(int));*/
    /*printf("b >> sizeof(int)*6=%x\n", b >> ((sizeof(int) * 2)));*/
    /*printf("m=%x\n", (0xFF000000 & (b >> (sizeof(int) * 6))));*/
    /*printf("b << sizeof(int)*6=%x\n", b << ((sizeof(int) * 6)));*/
    /*printf("l=%x\n", (0xFF000000 & (b << (sizeof(int) * 6))));*/
    /*printf("c=%x\n", c);*/
    printf("(%8x)(%8x)(%8x)\n", a, most(a), least(a));
    printf("(%8x)(%8x)(%8x)\n", b, most(b), least(b));
    printf("(%8x)(%8x)(%8x)\n", c, most(c), least(c));
}

int least(int x)
{
    return (0xFF000000 & (x << (sizeof(int) * 6)));
}

int most(int x)
{
    return (0xFF000000 & x);
    /*return (0xFF000000 & (x >> (sizeof(int) * 6)));*/
}
