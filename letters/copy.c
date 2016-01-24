
#include <stdio.h>

/* copy input to output */
int main(){
    printf("EOF != 'a': %d\n", 'a' != EOF);
    printf("EOF != EOF: %d\n", EOF != EOF);
    printf("EOF: %d\n", EOF);


    int c;

    while ((c = getchar()) != EOF){
        putchar(c);
    }
}
