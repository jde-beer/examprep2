
#include <stdio.h>
#include <unistd.h>
int        main(int argc, char **argv)
{
	char word[256][4096];
	int i;
	int j;
	int num;

	if(argc == 2)
	{
		i = 0;
		j = 0;
		num = 0;

		while(argv[1][i])
		{
			if(argv[1][i] == ' ')
			{
				num++;
				i++;
				j = 0;		
			}
			word[num][j] = argv[1][i];
			i++;
			j++;
		}
		j = 0;
		while(num >= 0)
		{
			if(word[num][j] == '\0')
			{
				if(num > 0)
				{
					write(1, " ", 1);
				}
				if(word[num][j] == '\0' && num == 0)
				{
					break;
				}
				num--;
				j = 0;
			}
			write(1, &word[num][j++], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}	
