#include <unistd.h>
#include <stdio.h>
typedef struct s_pal
{
    int size;
    int begin;
}t_pal;
void biggest_pal(char *str)
{
    t_pal pal;
    int i = -1;
    int j = 0;
    int k = 0;
    pal.size = 0;
    pal.begin = 0;
    while(str[++i])
    {
        j = 0;
        k = 1;
        while (str[i] == str[k + i])
            k++;  
        if (k >= pal.size)
        {
            pal.size = k;
            pal.begin = i;
        }
        while (++j && str[i + j + k - 1] == str[i - j])
            if (2 * j + k >= pal.size && str[i + j + k - 1] && str[i - j])
            {
                pal.size = 2 * j + k;
                pal.begin = i - j;
            }
    }
    write(1,str + pal.begin,pal.size);
}
int main(int ac, char **av)
{
    if (ac == 2)
        biggest_pal(av[1]);
    write(1,"\n",1);
}