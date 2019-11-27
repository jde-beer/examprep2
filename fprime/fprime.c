#include <stdlib.h>
#include <stdio.h>

void fprime(int n)
{
	int i = 2;
	if (n == 1)
	{
		printf("1");
		return ;
	}
	else if (n < 1)
		return ;
	while (i <= n)
	{
		if (n % i == 0)
		{
			printf("%i", i);
			n /= i;
			i = 1;
			if (n == 1)
				return ;
			else 
				printf("*");
		}
		i++;
	}
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		fprime(atoi(argv[1]));
	}
	printf("\n");
	return (0);
}
