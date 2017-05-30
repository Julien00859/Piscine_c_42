#include "../include/libft.h"

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0' - 1;
	while (++a < '8')
	{
		b  = a;
		while (++b < '9')
		{
			c = b;
			while (++c <= '9')
			{
				if (c != '2')
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				ft_putchar(a);
				ft_putchar(b);
				ft_putchar(c);
			}
		}
	}
}
