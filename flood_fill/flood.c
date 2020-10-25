
void fill(char **tab, t_point size, int x, int y, char c)
{
	if (x < 0 || y < 0 || x >= size.x || y >= size.y || tab[y][x] != c)
		return;
	tab[y][x] = 'F';
	fill(tab, size, x + 1, y, c);
	fill(tab, size, x - 1, y, c);
	fill(tab, size, x, y + 1, c);
	fill(tab, size, x, y - 1, c);
}
void flood_fill(char **tab, t_point size, t_point begin)
{
	char c;
	c = tab[begin.y][begin.x];
	fill(tab, size, begin.x, begin.y, c);
}
int main(void)
{
    t_point size = {8, 5};
    t_point begin = {0, 0};
    char **area;
    char *zone[] = {
        "1 1 1 1 1 1 1 1",
        "1 0 0 0 1 0 0 1",
        "1 0 0 1 0 0 0 1",
        "1 0 1 1 0 0 0 1",
        "1 1 1 0 0 0 0 1",
    };
    
    area = make_area((char **)zone, size);
    print_tab(area, size);
    flood_fill(area, size, begin);
    printf("\n");
    print_tab(area, size);
    return (0);
}
*/
