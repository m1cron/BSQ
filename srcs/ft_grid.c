#include "ft_bsq.h"

t_bool		ft_bigger_sqr(char *str, int x_y[2], t_grid_info *info, int size)
{
	int	x;
	int	y;
	int	start;

	x = size - 1;
	y = 0;
	start = info->length + x_y[0] + (x_y[1]) * (info->width + 1);
	if (x_y[0] + size > info->width)
		return (false);
	else if (x_y[1] + size > info->height)
		return (false);
	while (y < size - 1)
		if (str[start + x + y * (info->width + 1)] == info->empty)
			y++;
		else
			return (false);
	x = 0;
	while (x < size)
		if (str[start + x + y * (info->width + 1)] == info->empty)
			x++;
		else
			return (false);
	return (true);
}

void		ft_get_max_grid(t_grid_info *info, char *str, t_max_grid *max_grid)
{
	int		x_y[2];
	int		max;

	x_y[1] = 0;
	while (x_y[1] + max_grid->max < info->height)
	{
		x_y[0] = 0;
		while (x_y[0] + max_grid->max < info->width)
		{
			max = ft_check_case(str, info, x_y, max_grid->max);
			if (max > max_grid->max)
			{
				max_grid->max = max;
				max_grid->x = x_y[0];
				max_grid->y = x_y[1];
			}
			else if (max < 0)
			{
				if (x_y[0] + -max < info->width)
					x_y[0] = x_y[0] + -max;
			}
			x_y[0]++;
		}
		x_y[1]++;
	}
}

int			ft_check_case(char *str, t_grid_info *info, int x_y[2], int size)
{
	int		i;
	int		temp;

	i = size + 1;
	while (true)
	{
		if (x_y[0] + i > info->width)
			return (i - 1);
		else if (x_y[1] + i - 1 >= info->height)
			return (i - 1);
		temp = ft_check_square(str, x_y, info, i);
		if (temp > 0)
		{
			i++;
			while (ft_bigger_sqr(str, x_y, info, i))
				i++;
			return (i - 1);
		}
		else
			return (temp);
	}
}

int			ft_check_square(char *str, int x_y[2], t_grid_info *info, int size)
{
	int i;
	int j;
	int start;

	start = info->length + x_y[0] + (x_y[1]) * (info->width + 1);
	i = size - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < size)
		{
			if (str[start + i + j * (info->width + 1)] == info->let)
				return (-i);
			else if (str[start + i + j * (info->width + 1)] == '\n')
				return (false);
			j++;
		}
		i--;
	}
	return (true);
}

void		ft_fill_grid(t_max_grid *max_grid, char *str, t_grid_info *info)
{
	int		x;
	int		y;
	int		x_y;

	y = -1;
	x_y = info->length + max_grid->x + (max_grid->y) * (info->width + 1);
	while ((++y) < max_grid->max)
	{
		x = 0;
		while (x < max_grid->max)
			str[x_y + (x++) + y * (info->width + 1)] = info->fill;
	}
}