#include <stdio.h>
#include <stdlib.h>

int compare(int x, int y);

int main()
{
    int *p;
    p = (int *) malloc(128);
    printf("%d\n", sizeof(p));
    free(p);

    compare(1, 1);
    compare(1,2);
    return 0;
}

int compare(int x, int y)
{
    if(x == y) {
        printf("true");
    } else {
        printf("false");
    }
    return 0;
}
