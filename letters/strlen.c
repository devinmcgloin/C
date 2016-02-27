
#include <stdio.h>

int len(char * s1, char * s2);

int main()
{
	char * s1 = "hello";
	char * s2 = "strng";
	printf("%d", len(s1, s2));
}

int len(char * s1, char * s2)
{
	int counter = 0;

	while ((*s1) != '\0' && (*s2) != '\0')
	{
		counter += 2;
		s1++;
		s2++;
	}

	while ((*s1) != '\0')
	{
		counter++;
		s1++;
	}

	while ((*s2) != '\0')
	{
		counter++;
		s2++;
	}
	return counter;
}
