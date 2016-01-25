#include <stdio.h>

/* count digits, white space, others */

int max(int arr[]);

int main(){

	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; i++)
		ndigit[i] = 0;

	while((c = getchar()) != EOF)
		if ( c >= '0' && c <= '9')
			++ndigit[c-'0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;

	double largest = max (ndigit);
	
	printf("digits:\n");
	for(i = 0; i < 10; ++i){
		printf("Num=%d count=%6d: ",i, ndigit[i]);
		for(int j = 0; j < (ndigit[i] / largest) * 80; j++){
			printf("|");
		}
		printf("\n");
	}
		
	printf("white space = %d, other = %d\n", nwhite, nother);
}

int max(int arr[]){
	int max = 0;
	int size = sizeof(arr)/sizeof(arr[0]);
	for(int i = 0; i < size; i++){
		if(arr[i] > max)
			max = arr[i];
	}
	return max;
}


