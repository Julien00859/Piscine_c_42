#include "ft_putchar.c"

void	ft_print_comb(void)
{
	char unit;
	char ten;
	char hundred;

	unit = '2';
	ten = '1';
	hundred = '0';
	while (hundred < '8') {
		while (ten < '9') {
			while (unit < '9' + 1) {
				ft_putchar(hundred);
				ft_putchar(ten);
				ft_putchar(unit);
				ft_putchar('\n');
				unit++;
			}
			ten++;
			unit = ten + 1;
		}
		hundred++;
		ten = hundred;
	}
}

int 	main()
{
	ft_print_comb();
}
