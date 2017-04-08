#include "ft_putchar.c"

void	ft_print_numbers(void)
{
	char num;

	num = '0';
	while (num <= '9')
		ft_putchar(num++);
}

int 	main()
{
	ft_print_numbers();
	ft_putchar('\n');
}
