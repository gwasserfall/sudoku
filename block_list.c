#include "sudoku.h"

t_block *new_block(int fv, int x, int y, int val)
{
	t_block *block;

	if (!(block = malloc(sizeof(t_block))))
		return NULL;

	block->next = NULL;
	block->prev = NULL;
	block->fixed_value = fv;
	block->value = val;
	block->col = NULL;
	block->row = NULL;
	block->x = x;
	block->y = y;

	return (block);
}

void	append_block(t_block **board_start, t_block *new)
{
	t_block *board;

	board = *board_start;

	if (board)
	{
		while (board->next)
			board = board->next;
		board->next = new;
		new->prev = board;
	}
	else
		*board_start = new;
}