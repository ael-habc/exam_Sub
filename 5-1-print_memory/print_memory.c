#include <stddef.h>
void    print_memory(const void *addr, size_t size)
{
    unsigned int        i;
    int                 j;
    char                *hex;
    unsigned const char *ptr;
    char                str[17];
    ptr = addr;
    hex = "0123456789abcdef";
    i = 0;
    str[16] = '\0';
    while (i < size || i % 16)
    {
        j = -1;
        if (i < size)
        {
            write(1, hex + ptr[i] / 16, 1);
            write(1, hex + ptr[i] % 16, 1);
            str[i % 16] = (ptr[i] >= 32 && ptr[i] <= 126) ? ptr[i] : '.';
        }
        else
            write(1, "  ", 2);
        if (!(++i % 2))
            write(1, " ", 1);
        if (!(i % 16))
        {
            while (str[++j])
            {
                write(1, str + j, 1);
                str[j] = '\0';
            }
            write(1, "\n", 1);
        }
    }
}
