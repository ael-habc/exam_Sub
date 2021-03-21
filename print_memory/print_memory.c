#include <unistd.h>
#include <stdlib.h>
void	print_memory(const void *addr, size_t size)
{
    char *base;
    char line[17];
    unsigned char *str;
    size_t i = 0 ;
    int  j = -1;
    base = "0123456789abcdef";
    line[16] = '\0';
    str = (unsigned char *)addr;
    while (i < size || i % 16)
    {
        j = -1;
        if (i < size)
        {
            write(1,base + str[i] / 16,1);
            write(1,base + str[i] % 16,1);
            line[i % 16] = (str[i] >= 32 && str[i] <= 126) ? str[i] : '.';
        }
        else
            write(1, "  ",2);
        i++;
        if (!(i % 2))
            write(1, " ",1);
        if (!(i % 16))
        {
            while (line[++j])
            {
                write(1,&line[j],1);
                line[j] = '\0';
            }
            write(1,"\n",1);
        }
    }
}
