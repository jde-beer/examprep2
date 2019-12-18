#include <unistd.h>

int		ft_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

int		is_pal(char *str, int b, int e)
{
	while(b < e)
	{
		if (str[b] != str[e])
			return (0);
		b++;
		e--;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int begin;
	int end;
	int len;
	int size;
	char *big_pal;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	len = ft_strlen(argv[1]);
	end = len;
	begin = 0;
	size = 0;
	while (argv[1][begin] != '\0')
	{
		if ((end - begin + 1) >= size && is_pal(argv[1], begin, end))
		{
			size = end - begin + 1;
			big_pal = &argv[1][begin];
		}
		end--;
		if (begin > end)
		{
			begin++;
			end = len;
			if (end - begin + 1 < size)
				break;
		}
	}
	write(1, big_pal, size);
	write(1, "\n", 1);
	return (0);
}
