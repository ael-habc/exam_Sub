#include "t_point.h"
void fill(char **tab, int x,int y,t_point size, char c)
{
    if (x < 0 || y < 0 || x > size.x || y >size.y || tab[y][x] != c)
     return;
    tab[y][x] = 'F';
    fill(tab,x+1,y,size,c);
    fill(tab,x,y+1,size,c);
    fill(tab,x-1,y,size,c);
    fill(tab,x,y-1,size,c);
}
void  flood_fill(char **tab, t_point size, t_point begin)
{
    char c;
    c = tab[begin.y][begin.x];
    fill(tab,begin.x,begin.y,size,c);
}
