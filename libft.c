#include "sudoku.h"

int ft_strlen(char *line)
{
    int count;

    count = 0;
    while (*line)
    {
        count++;
        line++;
    }
    return (count);
}

void ft_putendl(char *str)
{
    write(1, str, ft_strlen(str));
    write(1, "\n", 1);
}