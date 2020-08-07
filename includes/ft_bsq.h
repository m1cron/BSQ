#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "ft_boolean.h"

/*
**	REMOVE THAT SHIT
*/
#include <stdio.h>
#include <time.h>


/*
**	Buffers (лень переделывать пусть будет так)
*/
unsigned int		g_buf_line;
unsigned int		g_buf_len;
char				g_buf_first_line[16];

/*
**	Grid struct
*/
typedef struct		s_grid_info
{
	int		height;
	int		length;
	int		width;
	char	empty;
	char	let;
	char	fill;
}					t_grid_info;

/*
**	Grid max square struct
*/
typedef struct		s_max_grid
{
	int	x;
	int	y;
	int	max;
}					t_max_grid;

/*
**	MAIN.C
*/
void				execution(char *arg);

/*
**	ft_board.c
*/
t_bool				ft_bigger_sqr(char *str, int x_y[2],
								t_grid_info *info, int size);
void				ft_get_max_grid(t_grid_info *info, char *str,
								t_max_grid *max_grid);
int					ft_check_case(char *str, t_grid_info *info,
								int x_y[2], int size);
int					ft_check_square(char *str, int x_y[2],
								t_grid_info *info, int size);
void				ft_fill_grid(t_max_grid *max_grid, char *str, t_grid_info *info);

/*
**	ft_parsing.c
*/
char				*ft_pars(int fd, unsigned int buff_size);
t_grid_info			*read_map(char *arg);
int					ft_get_width(char *st, t_grid_info *inf, int width);
void				read_key(void);
void				ft_start(char *str, t_grid_info	*info);

/*
**	ft_valid_line.c
*/
t_bool				valid_zero(char *str, int a);
t_grid_info			*ft_first_line(char *str);
t_max_grid			*ft_init_max_grid(void);

/*
**	ft_utils.c
*/
void				ft_putchar(char c);
void				ft_putstr(char *str);
int					ft_atoi(char *str);
void				ft_print_grid(char *str, unsigned int start);
int					ft_strlen_mod(char *str);

#endif
