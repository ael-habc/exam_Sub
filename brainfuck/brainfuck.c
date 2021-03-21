#include <unistd.h>
#include <stdlib.h>
int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;
        int count = 1;
        char *str;
        str= malloc(sizeof(char) * 2048);
        while (av[1][i])
        {
            (av[1][i] == '>') ? str++ : str;
            (av[1][i] == '<') ? str-- : str;
            (av[1][i] == '+') ? (*str)++ : *str;
            (av[1][i] == '-') ? (*str)-- : *str;
            (av[1][i] == '.') ? write(1,str,1) : 0;
            i++;
            if (av[1][i] == '[' && !(*str))
            {
                count = 1;
                while (count)
                {
                    i++;
                    if (av[1][i] == '[')
                        count++;
                    if (av[1][i] == ']')
                        count--;
                }
            }
            if (av[1][i] == ']' && (*str))
            {
                count = 1;
                while (count)
                {
                    i--;
                    if (av[1][i] == '[')
                        count--;
                    if (av[1][i] == ']')
                        count++;
                }
            }
        }
    }
}