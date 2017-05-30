#include <stdint.h>
#include "../include/libft.h"

void	ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	if (n < -9 || n > 9)
		ft_putnbr(abs(n / 10));
	ft_putchar('0' + abs(n % 10));
}
