#include <stdio.h>
#include <stdlib.h>
 char *ft_itoa(int n)
 {
     int nb;
     int nbr;
     int i;
     int count;
     char *str;
     count = 0;
     nb = n;
     if (n < 0)
     {
         nb *= -1;
         count++;
     }
     nbr  = nb;
     while (nb)
     {
         nb /= 10;
         count++;
     }
     if (!(str = (char *)malloc(sizeof(char) * count + 1)))
        return (NULL);
    i = count - 1;
    while (nbr)
    {
        str[i] = nbr % 10 + '0';
        nbr /= 10;
        i--;
    }
    if (n < 0)
        str[0] = '-';
    str[count] = '\0';
    return str;
 }
