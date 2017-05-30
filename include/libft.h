/*
 * libft.h
 * Copyright (C) 2017 dermenslof <francois@montaron.eu>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef LIBFT_H
# define LIBFT_H

#define abs(X) ((X) < 0 ? -(X) : (X))
#define sign(X) ((X) < 0 ? -1 : 1)
#define min(X, Y) ((X) < (Y) ? (X) : (Y))
#define max(X, Y) ((X) > (Y) ? (X) : (Y)) 

void	ft_putchar(int c);
void	ft_putnbr(int n);
void	ft_print_comb(void);
void	ft_print_comb2(void);
void	ft_print_combn(int i);

#endif /* !LIBFT_H */
