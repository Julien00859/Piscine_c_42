#include "ft_putchar.c"

void	ft_print_alphabet(void)
{
	char letter;

	letter = 'a';
	while (letter <= 'z')
		ft_putchar(letter++);
}

int 	main()
{
	ft_print_alphabet();
	ft_putchar('\n');
}
