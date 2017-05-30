#include "../include/libft.h"

void		ft_print_combn(int n)
{
	char	comb[10];
	int		i;

	*comb = '0';
	i = 0;
	while (++i < n)
		comb[i] = comb[i - 1] + 1;
	while ((i = -1))
	{
		while (++i < n)
			ft_putchar(comb[i]);
		while (i--)
		{
			if (comb[i] < '9' + 1 - n + i && ++comb[i])
			{
				while (i++ < n)
					comb[i] = comb[i - 1] + 1;
				break;
			}
			if (!i)
				return;
		}
		ft_putchar(',');
		ft_putchar(' ');
	}
}
