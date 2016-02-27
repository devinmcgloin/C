//
// Created by Devin McGloin on 1/22/16.
// Modify to print header above each table
// add c -> f table.
//

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 5

int FtoC(int F)
{
	return ( 5.0 / 9.0 ) * ( F - 32.0);
}

int CtoF(int C)
{
	return C / (5.0 / 9.0) + 32;
}

int main()
{
	double initial_temp, gen_temp_f, gen_temp_c;

	initial_temp = UPPER;

	printf("%s\t%s\t%s\t%s\n------------------------------\n", "Fahr", "Cels", "Cels", "Fahr");
	while (initial_temp >= LOWER)
	{
		gen_temp_c = FtoC(initial_temp);
		gen_temp_f = CtoF(initial_temp);
		printf("%3.0f\t%6.1f\t%3.0f\t%6.1f\n", initial_temp, gen_temp_c, initial_temp, gen_temp_f);
		initial_temp = initial_temp - STEP;
	}
}
