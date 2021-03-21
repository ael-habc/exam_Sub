#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int ftspace(char c)
{
    return (c == ' ' || c == '\t') ? 1 : 0;
}
void rostring(char *str)
{
    int i = 0, j = 0;
    while (str[i] && ftspace(str[i]))
        i++;
    j = i;
    while (str[i] && !ftspace(str[i]))
        i++;
    while (str[i])
    {
        if(!ftspace(str[i]) && ftspace(str[i-1]) && str[i])
        {
            while (str[i] && !ftspace(str[i]))
            {
                write(1,&str[i++],1);
            }
            write(1," ",1);
        }
        i++;
    }
    while(str[j] && !ftspace(str[j]))
    {
        write(1,&str[j],1);
        j++;
    }
}
int main(int ac, char **av)
{
    
    if (ac == 2)
        rostring(av[1]);
    write(1,"\n",1);
}