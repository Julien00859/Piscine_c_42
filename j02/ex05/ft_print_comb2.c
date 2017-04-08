#include "ft_putchar.c"

void	ft_print_comb2(void)
{
	char comb[4];

	comb[0] = 0;
	comb[1] = 0;
	comb[2] = 0;
	comb[3] = 1;
	while (1) {
		ft_putchar(comb[0] + '0');
		ft_putchar(comb[1] + '0');
		ft_putchar(' ');
		ft_putchar(comb[2] + '0');
		ft_putchar(comb[3] + '0');
		if (comb[0] != 9 || comb[1] != 8) {
			ft_putchar(',');
			ft_putchar(' ');
		} else
			return;
		if (comb[2] < 9	|| comb[3] < 9) {
			comb[2] += ++comb[3] / 10;
			comb[3] %= 10;
			continue;
		}
		comb[0] += ++comb[1] / 10;
		comb[1] %= 10;
		comb[3] = comb[1] + 1;
		comb[2] = comb[0] + comb[3] / 10;
		comb[3] %= 10;
	}
}

int 	main(void)
{
	ft_print_comb2();
	ft_putchar('\n');
}
