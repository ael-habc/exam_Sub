#include <stdlib.h>
#include <stdio.h>
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}
int ft_nbrlen(int nb)
{
    int i = 0;
    while (nb)
    {
        nb/= 10;
        i++;
    }
    return i;
}
char *ft_atoi(int nb)
{
    char *str;
    int count = 0;
    count = ft_nbrlen(nb);
    str= malloc(sizeof(char) * count + 1);
    str[count] = '\0';
    while (nb)
    {
        str[count] = nb % 10 + '0';
        nb /= 10;
        count--;
    }
    return str;
}
char *ft_join(char *s1,char *s2)
{
    int i = 0, j = 0,count = 0;
    char *s3;
    count = ft_strlen(s1)  + ft_strlen(s2);
    s3 = malloc(sizeof(char) * count + 1);
    while (s1[i])
    {
        s3[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        s3[i] = s2[j];
        i++;
        j++;
    }
    s3[count] = '\0';
    return s3;
}
char    *moment(unsigned int duration)
{
    if (duration == 0)
        return ("0 seconds ago.");
    if (duration == 1)
        return ("1 second ago.");
    if (duration < 60)
        return (ft_join(ft_atoi(duration)," seconds ago."));
    if (duration < 120)
        return ("1 minute ago.");
    if (duration < 3600)
        return (ft_join(ft_atoi(duration / 60)," minutes ago."));
    if (duration < (7200))
        return ("1 hour ago.");
    if (duration < (3600*24))
        return (ft_join(ft_atoi(duration / 3600)," hours ago."));
    if (duration < (3600*24*2))
        return ("1 day ago.");
    if (duration < (3600*24*30))
        return (ft_join(ft_atoi(duration / 3600*24)," days ago."));
    if (duration < (3600*24*30*2))
        return ("1 mounth ago.");
    else
        return (ft_join(ft_atoi(duration / 3600*24*30)," mounths ago."));
    
}

int main(int ac, char **av)
{
    if (ac ==2)
       printf("%s", moment(atoi(av[1])));
}

