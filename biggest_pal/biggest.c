#include <unistd.h>

typedef struct  s_pal
{
	int         begin;
	int         size;
}               t_pal;

void            biggest_pal(char *str)
{
	t_pal   pal;
	int     i;
	int     j;
	int     k;
	i = -1;
	pal.begin = 0;
	pal.size = 0;
	while (str[++i])
	{
		j = 0;
		k = 1;
		while (str[i] == str[k + i])
			k++;
		if (k >= pal.size)
		{
			pal.begin = i;
			pal.size = k;
		}
		while (++j && str[i + j + k - 1] == str[i - j])
			if (2 * j + k >= pal.size && str[i + j + k - 1] && str[i - j])
			{
				pal.begin = i - j;
				pal.size = 2 * j + k;
			}
	}
	write(1, str + pal.begin, pal.size);
}
int             main(int ac, char *av[])
{
	if (ac == 2)
		biggest_pal(av[1]);
	write(1, "\n", 1);
	return (0);
}
