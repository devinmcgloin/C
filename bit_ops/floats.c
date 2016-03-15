#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define FLOAT_BIAS 127
#define DOUBLE_BIAS 1023

char* get_bits_int(int n)
{
    //allocate memory to store the string
    int num_of_bits =  sizeof(int) * 8;  //*8 since there are 8 bits per byte
    char * bits_of_numbers = (char*) malloc(num_of_bits + 1);
    short bit ;
    int i;

    //convert value of n to bits
    for (i = 0; i < num_of_bits; i++)
    {
        bit = n & 1; //grab the last bit
        bits_of_numbers[num_of_bits - i - 1] = '0' + bit;
        n = n >> 1;  //remove the last bit
    }

    bits_of_numbers[num_of_bits] = '\0'; //end with a null character
    return bits_of_numbers;
}


char* get_bits_float(float f)
{
    //allocate memory to store the string
    int num_of_bits =  sizeof(float) * 8;  //*8 since there are 8 bits per byte
    char * bits_of_numbers = (char*) malloc(num_of_bits + 1);
    //interpret the bits as int (this is not equivalent to casting to int)
    int  p = *((int*)(&f));
    short bit ;
    int i;

    //convert value of n to bits
    for (i = 0; i < sizeof(float) * 8; i++)
    {
        bit = p & 1;  //grab the last bit
        bits_of_numbers[num_of_bits - i - 1] = '0' + bit;
        p = p >> 1;  //remove the last bit
    }

    bits_of_numbers[num_of_bits] = '\0'; //end with a null character
    return bits_of_numbers;
}

/* This function should take an array of integers (these are the values
 * read from your file) and the number of elements in the array. It should
 * return a string that corresponds to the original message.*/
char * convert_to_string(int text[] , int size)
{
    char * p = text;
    char * pnt = (p + size);
    pnt = '\0';
    return p;
}

/* This function should take a c-string as its parameter and convert the
 * first sizeof(int) bytes of the c-string to an integer that is returned.
 * Your function should work even if the c-string passed to it has fewer
 * than sizeof(int) characters (the missing bits should be filled with
 * zeroes.
 */
int convert_to_int(char * text)
{
    int *p = text;
    return (0x00000000 | *p);
}

/*say we have 0x1294 3293, we want only the 12.*/
int get_most_significant_byte(int x)
{
    return (0xFF000000 & x);
}

int get_least_significant_byte(int x)
{
    return (0xFF000000 & (x << (sizeof(int) * 6)));
}

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

/*This function should take a single precission floating point number
 * and return zero (a.k.a., false) when the value of f is not normalized,
 * and any other number (a.k.a., true) when the value of f is normalized.
 *
 * Normalized Occurs when exp != 000...0 and exp != 111...1
 */
int is_normalized(float f)
{
    if (get_exp(f) != 0x00000000 && get_exp(f) != 0x7F800000)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/*This function should take a single precission floating point number
 * and return zero (a.k.a., false) when the value of f is not denormalized,
 * and any other number (a.k.a., true) when the value of f is denormalized.
 *
 * Denormalized occurs when exp = 000...0
 *
 * */
int is_denormalized(float f)
{
    if (get_exp(f) == 0x00000000)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/*This function should take a single precission floating point number and
 * return zero (a.k.a., false) when the value of f is not special, and any
 * other number (a.k.a., true) when the value of f is special.i
 *
 * Special values occur when  exp = 111...1
 *
 * */
int is_special(float f)
{
    if (get_exp(f) == 0x7F800000)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/*This function should take a single precission floating point number and
 * return the numerical value of E from the above formula. The value of
 * E is related to the exp bits.
 * */
int get_E(float f)
{
    int E;

    if (is_normalized(f))
    {
        short exp;
        int i;
        int power = 1;
        char * bits = get_bits_float(f);

        for (i = 8; i >= 1; i--)
        {
            exp = exp + (power * (bits[i] - '0'));
            power = power * 2;
        }

        E = exp - 127;
        free(bits);
    }
    else if (is_denormalized(f))
    {
        E = 1 - FLOAT_BIAS;
    }
    else
    {
        E = 1 - FLOAT_BIAS;
    }

    return E;
}
/*This function should take a single precission floating point number
 * and return the numerical value of M from the above formula. The value
 * of M should be returned as a string with the appropriate leading character
 * and containing the decimal point. The value of M is related to the frac
 * bits.
 */
char * get_M(float f)
{
    char * M = get_bits_float(f);
    if(is_normalized(f))
        M[0] = '1';
    else if (is_denormalized(f))
        M[0] = '0';
    else
        return '\0';
    M[1] = '.';
    int i;
    int index = 2;

    for (i = 8; i <= 31; i++)
    {
        M[index] = M[i];
        index++;
    }

    M[index] = '\0';
    return M;
}
/*This function should take a single precission floating point number and
 * return the numerical value of s from the above formula, i.e. 0 for positive
 * values of f, 1 for negative values of f. The value of E is related to
 * the exp bits.
 */
int get_s(float f)
{
    if(get_sign(f) == 0x80000000)
        return 1;
    return 0;
}


/* for floats
 * s = 1
 * exp = 8
 * frac = 23
 *
 */
int main()
{
    float f =  1.2e+38;
    printf("value %10e\n", f);
    printf("all bits %45s\n", get_bits_float(f));
    unsigned int exp = get_exp(f);
    printf("exp  %15d %33s\n", exp, get_bits_int(exp));
    unsigned int frac = get_frac(f);
    printf("frac %15d %33s\n", frac, get_bits_int(frac));
    unsigned int sign = get_sign(f);
    printf("sign %15d %33s\n", sign, get_bits_int(sign));

    if (is_normalized(f))
    {
        printf("%e is normalized\n", f);
    }
    else if (is_special(f))
    {
        printf("%e is special\n", f);
    }
    else if (is_denormalized(f))
    {
        printf("%e is denormalized\n", f);
    }

    printf("E = %d\n", get_E(f));
    printf("M = %s\n", get_M(f));
    printf("S = %d\n", get_s(f));
}
