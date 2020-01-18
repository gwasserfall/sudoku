#include "sudoku.h"

t_grid   *new_grid(t_block *block)
{
    t_grid   *grid;

    if (!(grid = malloc(sizeof(t_grid))))
        return (NULL);

    grid->next = NULL;
    grid->block = block;
    return (grid);
}

void append_grid(t_grid **grids, t_grid *new)
{
    t_grid *grid;

    grid = *grids;

    if (grid)
    {
        while (grid->next)
            grid = grid->next;
        grid->next = new;
    }
    else
        *grids = new;
}

t_grid   *get_grid_for_cord(t_grid *grid, int x, int y)
{
    while (grid)
    {
        if (grid->block->y == y)
            return (grid);
    }
    return (NULL);
}