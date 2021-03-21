#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
    if (ac == 2)
    {
        int prime = 2,nb = 0;
        nb = atoi(av[1]);
        if (nb == 1 || nb == 0)
            printf("%d",nb);
        while (nb >= prime)
        {
           if (!(nb % prime))
           {
               printf("%d",prime);
               nb /= prime;
               (nb > 1) ? printf("*"): 0;
               prime--;
           } 
           prime++;
        }
    }
    printf("\n");
}