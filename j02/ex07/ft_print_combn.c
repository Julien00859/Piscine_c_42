#include "ft_putchar.c"

void 	ft_print_combn(int n)
{
	char comb[10];
	int i;

	comb[0] = '0';
	i = 0;
	while(++i < n)
		comb[i] = comb[i-1]+1;
	while (1) {
		i = 0;
		while (i < n)
			ft_putchar(comb[i++]);
		i = n;
		while (i--) {
			if (comb[i] < '9' + 1 - n + i) {
				comb[i]++;
				while (i++ < n)
					comb[i] = comb[i-1]+1;
				break;
			}
			if (!(i)) return;
		}
		ft_putchar(',');
		ft_putchar(' ');
	}	
}

int 	main() 
{
	ft_print_combn(5);
	ft_putchar('\n');
}
