#ifndef SUDOKU_H
# define SUDOKU_H
# define INVALID 0
# define EMPTY -1
# define true 1
# define false 0

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef	struct		s_row
{
	struct s_row	*next;
	struct s_block	*block;
}					t_row;

typedef	struct		s_col
{
	struct s_col	*next;
	struct s_block	*block;
}					t_col;

typedef	struct		s_grid
{
	struct s_grid 	*next;
	struct s_block	*block;
}					t_grid;

typedef struct		s_block
{
	struct s_block 	*next;
	struct s_block 	*prev;
	struct s_block 	*row;
	struct s_block 	*col;
	struct s_block 	*grid;

	
	int				fixed_value;
	int				value;
	int				x;
	int				y;
}					t_block;

typedef	struct		s_state
{
	t_grid			*top_grids;
	t_col			*top_cols;
	t_row			*top_rows;
	t_block			*board;
}					t_state;




int		is_valid_length(char *line);
int		is_valid_digit(char c);
int		validate_input(int argc, char **argv);
int		is_valid_line(char *line);

int		exit_with_error();

// libft
int		ft_strlen(char *line);
void	ft_putendl(char *str);
t_block	*read_input_block(char c, int x, int y);
void	build_board(t_block **board, char **argv);
t_block *new_block(int fv, int x, int y, int val);
void	append_block(t_block **board_start, t_block *new);


t_col   	*get_cols_for_cord(t_col *col, int x);
void 		append_col(t_col **cols, t_col *new);
t_row   	*new_col(t_block *block);
t_grid  	*new_grid(t_block *block);
void 		append_grid(t_grid **grids, t_grid *new);
t_grid  	*get_grid_for_cord(t_grid *grid, int x, int y);
t_row   	*new_row(t_block *block);
void 		append_row(t_row **rows, t_row *new);
t_row   	*get_rows_for_cord(t_row *row, int y);

#endif