#include "sudoku.h"

t_row   *new_row(t_block *block)
{
    t_row   *row;

    if (!(row = malloc(sizeof(t_row))))
        return (NULL);

    row->next = NULL;
    row->block = block;
    return (row);
}

void append_row(t_row **rows, t_row *new)
{
    t_row *row;

    row = *rows;

    if (row)
    {
        while (row->next)
            row = row->next;
        row->next = new;
    }
    else
        *rows = new;
}

t_row   *get_rows_for_cord(t_row *row, int y)
{
    while (row)
    {
        if (row->block->y == y)
            return (row);
    }
    return (NULL);
}