#include <stdlib.h>
#include <stdio.h>
int ft_nbrlen(int n,int base)
{
    int i = 0;
    while (n)
    {
        n /= base;
        i++;
    }
    return i;

}
char	*ft_itoa_base(int value, int base)
{
    if (base < 2 || base > 16)
        return(0);
    unsigned int nb;
    int i = 0;
    int count = 0;
    char *str;
    nb = value;
    if (value == 0)
        return ("0");
    
    if (value < 0)
    {
        nb *= -1;
        if (base == 10)
            count++;
    }
    count = ft_nbrlen(nb,base);
    str = malloc(sizeof(char) * count + 1);
    str[count] = '\0';
    i = count;
    while (i--)
    {
        str[i] = (nb % base <= 10) ? (nb % base + 'A' - 10) : (nb % base + '0');
        nb/= base;
    }
    str[0] = (value < 0 && base == 10) ? '-' : str[0];
    return str;
}
int main()
{
    printf("%s",ft_itoa_base(0,1));
}