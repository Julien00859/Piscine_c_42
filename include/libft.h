#ifndef LIBFT_H
# define LIBFT_H

#define ft_abs(X) ((X) < 0 ? -(X) : (X))
#define ft_sign(X) ((X) < 0 ? -1 : 1)
#define ft_min(X, Y) ((X) < (Y) ? (X) : (Y))
#define ft_max(X, Y) ((X) > (Y) ? (X) : (Y)) 

void	ft_putchar(int c);
void	ft_putnbr(int n);
void	ft_print_comb(void);
void	ft_print_comb2(void);
void	ft_print_combn(int i);

#endif /* !LIBFT_H */
