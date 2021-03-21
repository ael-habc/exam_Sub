#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
	if (ac ==2)
	{
		char str[200][200];
		int i = 0;
		int j = 0;
		int count = 0;
		while (av[1][i])
		{
			// escape space and start a new case
			if (av[1][i] == ' ')
			{
				i++;
				count++;
				j = 0;
			}
			// copie av in str
			str[count][j] = av[1][i];
			i++;
			j++;
		}
		j = 0;
		i = 0;
		while (count >= 0)
		{
			j = 0;
			while (str[count][j])
				write(1,&str[count][j++],1);
			(count--) ? write(1," ",1) : 0;
		}
	}
	write(1,"\n",1);
}