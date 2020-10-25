#include <unistd.h>
int ft_isblank(char c)
{
	return(c == ' ' || c == '\t');
}
void rostring(char *s)
{
	int wordlen = 0, i = 0;
	
	while(s[i])
	{
		while (s[i] && ft_isblank(s[i]))
			i++;
		if (wordlen == 0)
			while(s[i] && !ft_isblank(s[i++]))
				wordlen++;
		else
		{
			while(s[i] && write(1,&s[i++],1));
			write(1, " ", 1);
		}
	}
	i = 0;
	while(ft_isblank(s[i]))
		i++;
	while(wordlen--)
		write(1,&s[i++],1);
}
int		main(int ac, char **av)
{
	if (ac > 1 && *av[1])
		rostring(av[1]);
	write(1, "\n", 1);
	return (0);
}