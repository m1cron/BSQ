#include "ft_bsq.h"

char	*ft_pars(int fd, unsigned int buff_size)
{
	char	*str;

	if ((str = (char*)malloc(sizeof(char) * (buff_size + 17))))
		read(fd, str, buff_size + 16);
	return (str);	
}

void	read_key(void)
{
	unsigned short		fd;
	char				buf;
	int 		temp;

	fd = open("temp", O_WRONLY | O_CREAT | O_TRUNC, 0600);
	while ((temp = read(0, &buf, 1)))
	{
		if (temp == -1)
		{
			ft_putstr("map error\n");
			close(fd);
			return ;
		}
		write(fd, &buf, 1);
	}
	close(fd);
	execution("temp");
}

t_grid_info	*read_map(char *arg)
{
	unsigned short	fd;
	char			buf;
	int				size;
	t_grid_info		*info;

	fd = open(arg, O_RDONLY);
	size = 0;
	while (size += read(fd, &buf, 1))
	{
		if (size < 0)
			return (NULL);
		g_buf_first_line[size - 1] = buf;
		if (buf == '\n')
			break ;
	}
	info = ft_first_line(g_buf_first_line);
	g_buf_len = 0;
	while ((g_buf_len += read(fd, &buf, 1)) && buf != '\n')
		;
	close(fd);
	return (info);
}

int		ft_get_width(char *st, t_grid_info *inf, int width)
{
	int		i;
	int		c;
	int		lines;

	i = inf->length - 1;
	c = 0;
	lines = 0;
	while (st[++i])
		if (st[i] == '\n')
		{
			if (width != -1 && width != c)
				return (-1);
			width = c;
			c = 0;
			lines++;
		}
		else if (st[i] != inf->empty && st[i] != inf->let)
			return (-1);
		else if (c == 2147483647)
			return (-1);
		else
			c++;
	if (lines == inf->height)
		return (width);
	return (-1);
}

void	ft_start(char *str, t_grid_info *info)
{
	t_max_grid	*max_grid;
	int			width;

	max_grid = ft_init_max_grid();
	if (info && str)
	{
		width = -1;
		info->width = ft_get_width(str, info, width);
		if (info->width > 0)
		{
			ft_get_max_grid(info, str, max_grid);
			ft_fill_grid(max_grid, str, info);
			ft_print_grid(str, info->length);
			free(str);
		}
		else
			ft_putstr("map error\n");
	}
	else
		ft_putstr("map error\n");
	free(max_grid);
}