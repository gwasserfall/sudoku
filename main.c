#include "sudoku.h"

t_block	*get_block_by_cord(t_block *board, int x, int y)
{
	while (board)
	{
		if (board->x == x && board->y == y)
			return (board);
		board = board->next;
	}
	return (NULL);
}

void set_block_rows(t_state *state)
{
	t_block *next;
	t_block *row;
	int y;
	int x;

	y = 0;
	while (y <= 8)
	{
		x = 0;
		while (x < 8)
		{
			row = get_block_by_cord(state->board, x, y);
			row->row = get_block_by_cord(state->board, ++x, y);
		}
		y++;
	}
}

void set_block_cols(t_state *state)
{
	t_block *next;
	t_block *col;
	int y;
	int x;

	x = 0;
	while (x <= 8)
	{
		y = 0;
		while (y < 8)
		{
			col = get_block_by_cord(state->board, x, y);
			col->col = get_block_by_cord(state->board, x, ++y);
		}
		x++;
	}
}

void	set_block_grids(t_state *state, t_block *start)
{
	t_block *grid;
	int x;
	int y;

	y = start->y;

	while (y < (3 + start->y))
	{
		x = start->x;
		while (x < (3 + start->x))
		{
			grid = get_block_by_cord(state->board, x, y);
			x++;
			if (x == (3 + start->x))
				grid->grid = get_block_by_cord(state->board, start->x, y + 1);
			else
				grid->grid = get_block_by_cord(state->board, x, y);
		}
		y++;
	}
	grid->grid = start;
}

void	init_state(t_state *state, char **argv)
{
	state->board = NULL;
	int col;
	int row;

	build_board(&state->board, ++argv);
	set_block_rows(state);
	set_block_cols(state);
	
	row = 0;
	while (row <= 6)
	{
		col = 0;
		while (col <= 6)
		{
			set_block_grids(state, get_block_by_cord(state->board, col, row));
			col += 3;
		}
		row += 3;
	}
}

int valid_grid(t_block *block)
{
	t_block *runner;

	runner = block->grid;
	while (runner != block)
	{
		if (runner->value == block->value)
			return (0);
		runner = runner->grid;
	}
	return (1);
}

int valid_row(t_block *board, t_block *block)
{
	t_block *start;

	start = get_block_by_cord(board, 0, block->y);

	while (start)
	{
		if (start != block)
		{
			if (start->value == block->value)
				return (false);
		}
		start = start->row;
	}
	return (true);
}

int valid_col(t_block *board, t_block *block)
{
	t_block *start;

	start = get_block_by_cord(board, block->x, 0);

	while (start)
	{
		if (start != block)
		{
			if (start->value == block->value)
				return (false);
		}
		start = start->col;
	}
	return (true);
}

int	valid_position(t_block *board, t_block *block)
{
	if (!valid_grid(block))
		return (false);
	if (!valid_col(board, block))
		return (false);
	if (!valid_row(board, block))
		return (false);
	return (true);
}

void print_board(t_state state)
{
	printf("\e[1;1H\e[2J");
	sleep(1000);

	int row;

	row = state.board->y;
	while (state.board)
	{

		state.board = state.board->next;
	}
}


void	next_block(t_state s, t_block *block)
{

	print_board(s);

	if (!block)
		return ;

	if (!block->fixed_value)
	{
		block->value = (block->value == EMPTY) ? 1 : block->value++;
		next_block(s, block->next);
	}
	else
	{
		next_block(s, block->next);	
	}
}


int solve_puzzle(t_state state)
{
	next_block(state, state.board);
}


int main(int argc, char **argv)
{

	t_state state;

    if (!validate_input(argc, argv))
		return exit_with_error();

	init_state(&state, argv);

	solve_puzzle(state);

	return (0);
}
