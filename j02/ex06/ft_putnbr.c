#include "ft_putchar.c"

void	ft_putnbr(int nb)
{
	int power10;

	power10 = 1;
	while (nb / power10 > 10)
		power10 *= 10;
	while (nb) {
		ft_putchar('0' + nb / power10);
		nb %= power10;
		power10 /= 10;
	}
	
}

void main()
{
	ft_putnbr(42);
	ft_putchar(' ');
	ft_putnbr(16383);
	ft_putchar('\n');
}
