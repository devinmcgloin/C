#include <stdio.h>

int by_value(int x, int y);
int by_pointer(int * x, int * y);

int main(){
    int a = 5;
    int b = 7;

    printf("%2d %2d\n", a, b);
    by_value(a, b);
    printf("%2d %2d\n", a, b);
    by_pointer(&a, &b);
    printf("%2d %2d\n", a, b);
}

int by_value(int x, int y){
    x = 1;
    y = 10;
   printf("%2d %2d\n", x, y);
   return 0;
}

int by_pointer(int * x, int * y){
    (*x) = 1;
    (*y) = 10;
    printf("%2d %2d\n", *x, *y);
    return 0;
}
