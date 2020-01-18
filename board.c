#include "sudoku.h"

t_block	*read_input_block(char c, int x, int y)
{
	if (c == '.')
		return (new_block(false, x, y, EMPTY));
	else
		return (new_block(true, x, y, (c - '0')));
}

void	build_board(t_block **board, char **argv)
{
	char	*line;
	int		x;
	int		y;

	y = 0;
	while (*argv)
	{
		x = 0;
		line = *argv;
		while (*line)
		{
			append_block(board, read_input_block(*line, x, y));
			x++;
			line++;
		}
		y++;
		argv++;
	}
}