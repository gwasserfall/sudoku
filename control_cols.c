#include "sudoku.h"

t_row   *new_col(t_block *block)
{
    t_row   *col;

    if (!(col = malloc(sizeof(t_col))))
        return (NULL);

    col->next = NULL;
    col->block = block;
    return (col);
}

void append_col(t_col **cols, t_col *new)
{
    t_col *col;

    col = *cols;

    if (col)
    {
        while (col->next)
            col = col->next;
        col->next = new;
    }
    else
        *cols = new;
}

t_col   *get_cols_for_cord(t_col *col, int x)
{
    while (col)
    {
        if (col->block->x == x)
            return (col);
    }
    return (NULL);
}