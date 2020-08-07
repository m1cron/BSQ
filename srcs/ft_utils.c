#include <unistd.h>
#include "ft_bsq.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
}

void		ft_print_grid(char *str, unsigned int start)
{
	unsigned int	i;

	i = 0;
	while (str[start + i])
		i++;
	write(1, &str[start], i);
}

int			ft_atoi(char *str)
{
	int				nb;
	unsigned short	i;

	nb = 0;
	i = 0;
	while (str[i] <= 57 && str[i] >= 48)
		nb = nb * 10 + str[i++] - 48;
	return (nb);
}

int		ft_strlen_mod(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i > 16)
			return (0);
		i++;
		if (str[i] == '\n')
			return (i + 1);
	}
	return (i);
}