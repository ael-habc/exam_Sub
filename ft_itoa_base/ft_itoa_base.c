#include <stdlib.h>
#include <stdio.h>
char *ft_itoa_base(int value, int base)
{
    char *s;
    unsigned long nb;
    unsigned long n;
    int i= 0;
    int count = 0;
    int sign = 0;
    nb = value;
    if (value < 0)
    {
        nb *= -1;
        if (base == 10)
        {
            count++;
            sign = -1;
        }
    }
    n = nb;
    while(nb)
    {
        count++;
        nb /= base;
    }
    s = malloc(sizeof(char) * count + 1);
    i = count;
    s[count] = '\0';
    while (i--)
    {
        s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
        n /= base;
    }
    (sign == -1) ? s[0] = '-' : 0; 
    return (s);
}
int main(int ac , char **av)
{
    printf("%s",ft_itoa_bahse(atoi(av[1]), atoi(av[2])));
    return(0);
}
