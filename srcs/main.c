#include "ft_bsq.h"

void	execution(char *arg)
{
	unsigned short	fd;
	char			*str;
	t_grid_info		*grid_info;

	if ((fd = open(arg, O_RDONLY)) > 0)
	{
		if (!(grid_info = read_map(arg)))
		{
			ft_putstr("map error\n");
			return ;
		}
		str = ft_pars(fd, g_buf_len * g_buf_line);
		ft_start(str, grid_info);
		free(grid_info);
	}
	else
		ft_putstr("map error\n");
	close(fd);
}

int		main(int argc, char **argv)
{
	clock_t start = clock();
	int		i;

	i = 0;
	if (argc > 1)
		while (++i < argc)
		{
			if (i > 1) // ВОТ СУКА ИЗЗА ЭТОЙ ХУЙНИ МЫ ПОЛУЧИЛИ НАХУЙ 0 ИДИТЕ НАХУЙ 
				ft_putchar('\n');
			execution(argv[i]);
		}
	else
		read_key();
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time >>> %f\nlines >>> %u\nlen pre line >>> %u\nGrid MxN >>> %u\n", 
				seconds, g_buf_line, g_buf_len, g_buf_line * g_buf_len);
	return (SUCCESS);
}