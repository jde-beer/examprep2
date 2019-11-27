#include <unistd.h>

int		main(int argc, char **argv)
{
	int	tab[4096];
	int i;
	int *ptr;
	int loop;

	ptr = tab;
	i = 0;
	if(argc == 2)
	{
		while(argv[1][i])
		{
			if (argv[1][i] == '>')
				ptr++;
			else if (argv[1][i] == '<')
				ptr--;
			else if (argv[1][i] == '+')
				++(*ptr);
			else if (argv[1][i] == '-')
				--(*ptr);
			else if (argv[1][i] == '.')
				write(1, ptr, 1);
			else if (argv[1][i] == '[' && *ptr == 0)
			{
				loop = 1;
				while (loop != 0)
				{
					i++;
					if (argv[1][i] == '[')
						loop++;
					if (argv[1][i] == ']')
						loop--;
				}
			}
			else if (argv[1][i] == ']' && *ptr != 0)
			{
				loop = 1;
				while (loop != 0)
				{
					i--;
					if (argv[1][i] == ']')
						loop++;
					if (argv[1][i] == '[')
						loop--;
				}
			}
			i++;
		}
	}
}
