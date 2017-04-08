#include "ft_putchar.c"

void	ft_print_reverse_alphabet(void) 
{
	char letter;

	letter = 'z';
	while (letter >= 'a') {
		ft_putchar(letter);
		letter--;
	}
}

int		main()
{
	ft_print_reverse_alphabet();
	ft_putchar('\n');
}
