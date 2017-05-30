#include "../include/libft.h"

void	ft_print_comb2(void)
{
	int	a;
	int b;
	
	a = -1;
	while (++a < 99)
	{
		b = a;
		while (++b <= 99)
		{
			if (b != 1)
				ft_putchar(',');
			ft_putnbr(a);
			ft_putchar(' ');
			ft_putnbr(b);	
		}
	}
}
