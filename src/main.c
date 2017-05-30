#include "unit_test.h"
#include "libft.h"
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

void stdout_to_pipe(int* fd) 
{
	pipe(fd);
	fd[2] = dup(1);
	dup2(fd[1], 1);
}

void pipe_to_stdout(int* fd) 
{
	dup2(fd[2], 1);
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
}

UT_TEST(ft_putchar)
{
	int fd[3];
	char buffer[10];
	
	stdout_to_pipe(fd);

	ft_putchar('H');
	ft_putchar('i');
	ft_putchar(' ');
	ft_putchar('S');
	ft_putchar('D');
	ft_putchar('D');
	ft_putchar(' ');
	ft_putchar('!');
	ft_putchar('\n');

	read(fd[0], buffer, 9);
	buffer[9] = '\0';

	pipe_to_stdout(fd);

	UT_ASSERT_EQ(strcmp(buffer, "Hi SDD !\n"), 0);
}

UT_TEST(ft_putnbr)
{
	char buffer[35];
	int fd[3];

	stdout_to_pipe(fd);

	ft_putnbr(INT_MIN);
	ft_putchar(' ');
	ft_putnbr(-39);
	ft_putchar(' ');
	ft_putnbr(0);
	ft_putchar(' ');
	ft_putnbr(5);
	ft_putchar(' ');
	ft_putnbr(129);
	ft_putchar(' ');
	ft_putnbr(INT_MAX);

	read(fd[0], buffer, 34);
	buffer[34] = '\0';

	pipe_to_stdout(fd);

	UT_ASSERT_EQ(strcmp(buffer, "-2147483648 -39 0 5 129 2147483647"), 0);
}

UT_TEST(ft_print_comb)
{
	char buffer[599];
	int fd[3];

	stdout_to_pipe(fd);

	ft_print_comb();
	read(fd[0], buffer, 598);
	buffer[598] = '\0';

	pipe_to_stdout(fd);

	UT_ASSERT_EQ(strcmp(buffer, "012, 013, 014, 015, 016, 017, 018, 019, 023, 024, 025, 026, 027, 028, 029, 034, 035, 036, 037, 038, 039, 045, 046, 047, 048, 049, 056, 057, 058, 059, 067, 068, 069, 078, 079, 089, 123, 124, 125, 126, 127, 128, 129, 134, 135, 136, 137, 138, 139, 145, 146, 147, 148, 149, 156, 157, 158, 159, 167, 168, 169, 178, 179, 189, 234, 235, 236, 237, 238, 239, 245, 246, 247, 248, 249, 256, 257, 258, 259, 267, 268, 269, 278, 279, 289, 345, 346, 347, 348, 349, 356, 357, 358, 359, 367, 368, 369, 378, 379, 389, 456, 457, 458, 459, 467, 468, 469, 478, 479, 489, 567, 568, 569, 578, 579, 589, 678, 679, 689, 789"), 0);
}

UT_TEST(ft_print_combn)
{
	char buffer_comb9[12];
	char buffer_comb3[599];
	char buffer_comb[599];
	int fd[3];

	stdout_to_pipe(fd);

	ft_print_combn(10);
	read(fd[0], buffer_comb9, 11);
	buffer_comb9[11] = '\0';

	ft_print_combn(3);
	read(fd[0], buffer_comb3, 598);
	buffer_comb3[598] = '\0';

	ft_print_comb();
	read(fd[0], buffer_comb, 598);
	buffer_comb[598] = '\0';

	pipe_to_stdout(fd);

	UT_ASSERT_EQ(strcmp(buffer_comb9, "0123456789"), 0);
	UT_ASSERT_EQ(strcmp(buffer_comb3, buffer_comb), 0);
}


int	main(void)
{
	UT_ADD_TEST(ft_putchar);
	UT_ADD_TEST(ft_putnbr);
	UT_ADD_TEST(ft_print_comb);
	UT_ADD_TEST(ft_print_combn);
	UT_RUN_ALL_TESTS();
	return (0);
}

