#include <stdlib.h>
#include <stdio.h>
int nbrlen(int c)
{
    int i = 0;
    while (c)
    {
        i++;
        c/= 10;
    }
    return i;
}
int ft_strlen(char *c)
{
    int i = 0;
    while(c[i])
    {
        i++;
    }
    return i;
}
char *ft_strjoin(char *s1, char *s2)
{
    int i = 0, j = 0;;
    int x = 0;
    char *s3;
    x = ft_strlen(s1) + ft_strlen(s2);
    s3 = malloc(sizeof(char) * x + 1);
    while(s1[i])
    {
        s3[i] = s1[i];
        i++;
    }
    while(s2[j])
    {
        s3[i] = s2[j];
        i++;
        j++;
    }
    s3[i] = '\0';
    return s3;
}
char *ft_itoa(int c)
{
    int i = 0;
    char *s;
    int n;
    int x = 0;
    x = nbrlen(c);
    n = c;
    s = malloc(sizeof(char) * x + 1);
    s[x] = '\0';
    i = x;
    while(i--)
    {
        s[i] = n % 10 + '0';
        n /= 10;
    }
    return s;
}
char    *moment(unsigned int duration)
{
    if(duration == 1)
        return("1 second ago.");
    else if (duration < 60)
        return(ft_strjoin(ft_itoa(duration), " seconds ago."));
    else if (duration < 120)
        return("1 minute ago.");
    else if (duration < 3600)
        return(ft_strjoin(ft_itoa(duration / 60), " minutes ago."));
    else if (duration < 3600 * 2)
        return("1 hour ago.");
    else if (duration < 3600 * 24)
        return(ft_strjoin(ft_itoa(duration / 3600), " hours ago."));
    else if (duration < 3600 * 24 *2)
        return("1 day ago.");
    else if (duration < 3600 * 24 * 30)
        return(ft_strjoin(ft_itoa(duration / (3600 * 24)), " day ago."));
    else if (duration < 3600 * 24 * 30 * 2)
        return ("1 mount ago.");
    else
        return(ft_strjoin(ft_itoa(duration / (3600 * 24 * 30)), " day ago."));
}
int main(int ac, char **av)
{
    printf("%s",moment((atoi(av[1]))));
}