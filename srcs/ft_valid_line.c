#include "ft_bsq.h"

t_bool		valid_zero(char *str, int a)
{
	int i;
	int b;

	i = 0;
	b = a - 5;
	if (a < 5)
		return (false);
	if ((str[a - 3] == str[a - 2]) || (str[a - 2] == str[a - 4]))
		return (false);
	else if (str[a - 4] == str[a - 3])
		return (false);
	if (b == 0 && str[0] <= 57 && str[0] >= 48)
		return (true);
	while (i <= b)
	{
		if (str[i] > 57 || str[i] < 48)
			return (false);
		i++;
	}
	return (true);
}

t_grid_info		*ft_first_line(char *str)
{
	t_grid_info	*ptr;
	int		zero_i;

	ptr = NULL;
	zero_i = ft_strlen_mod(str);
	if (valid_zero(str, zero_i))
	{
		ptr = (t_grid_info *)malloc(sizeof(t_grid_info));
		ptr->height = ft_atoi(str);
		g_buf_line = ptr->height;
		ptr->length = zero_i;
		ptr->empty = str[zero_i - 4];
		ptr->let = str[zero_i - 3];
		ptr->fill = str[zero_i - 2];
	}
	return (ptr);
}

t_max_grid	*ft_init_max_grid(void)
{
	t_max_grid	*ptr;

	if (!(ptr = (t_max_grid *)malloc(sizeof(t_max_grid))))
		return (NULL);
	ptr->x = 0;
	ptr->y = 0;
	ptr->max = 0;
	return (ptr);
}