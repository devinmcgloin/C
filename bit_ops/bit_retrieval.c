#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * For floats
 * s = first bit
 * exp = 8 bits
 * frac = 23 bits
 */


unsigned int * get_sign(float f)
{
    unsigned int *fi = &f;
    unsigned int exp = (*fi & 0x80000000);
    return exp;
}

unsigned int * get_exp(float f)
{
    unsigned int *fi = &f;
    unsigned int frac = (*fi & 0x7F800000);
    return frac;
}


unsigned int * get_frac(float f)
{
    unsigned int *fi = &f;
    unsigned int frac = (*fi & 0x007FFFFF);
    return frac;
}

char* get_bits_int(int n)
{
    //allocate memory to store the string
    int num_of_bits =  sizeof(int) * 8;  //*8 since there are 8 bits per byte
    char * bits_of_numbers = (char*) malloc(num_of_bits + 1);
    short bit ;
    int i;

    //convert value of n to bits
    for(i = 0; i < num_of_bits; i++) {
        bit = n & 1; //grab the last bit
        bits_of_numbers[num_of_bits - i - 1] = '0' + bit;
        n = n >> 1;  //remove the last bit
    }

    bits_of_numbers[num_of_bits] = '\0'; //end with a null character
    return bits_of_numbers;
}

char* get_bits_float(float f)
{
    // allocate memory to store the string
    int num_of_bits =  sizeof(float) * 8;  //*8 since there are 8 bits per byte
    char * bits_of_numbers = (char*) malloc(num_of_bits + 1);
    //interpret the bits as int (this is not equivalent to casting to int)
    int  p = *((int*)(&f));
    short bit ;
    int i;

    //convert value of n to bits
    for(i = 0; i < sizeof(float) * 8; i++) {
        bit = p & 1;  //grab the last bit
        bits_of_numbers[num_of_bits - i - 1] = '0' + bit;
        p = p >> 1;  //remove the last bit
    }

    bits_of_numbers[num_of_bits] = '\0'; //end with a null character
    return bits_of_numbers;
}


int main()
{
    float x = 1.200000e+38;
    printf("All  %16s \n", get_bits_float(x));
    printf("   W %16s \n\n", "01111110101101001000111001010010");

    printf("Exp  %16s %10d\n", get_bits_int(get_exp(x)), get_exp(x));
    printf("   M %16s \n", get_bits_int(0x7F800000));
    printf("   W %16s %10d\n\n", "01111110100000000000000000000000", 2122317824);

    printf("Frac %16s %10d\n", get_bits_int(get_frac(x)), get_frac(x));
    printf("   M %16s \n", get_bits_int(0x007FFFFF));
    printf("   W %16s %10d\n\n", "00000000001101001000111001010010", 3444306);

    printf("Sign %16s %10d\n", get_bits_int(get_sign(x)), get_sign(x));
    printf("   M %16s \n", get_bits_int(0x80000000));
    printf("   W %16s %10d\n\n", "00000000000000000000000000000000", 0);

    printf("All  %16s \n", get_bits_float(x));
}

/*value    1.200000e+38*/
/*all bits*/
/*exp      2122317824    *01111110101101001000111001010010**/
/*frac        3444306*/
/*sign              0*/
/*01111110101101001000111001010010*/
/*01111110100000000000000000000000*/
/*00000000001101001000111001010010*/
/*00000000000000000000000000000000*/
