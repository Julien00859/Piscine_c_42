#
# Makefile
# dermenslof, 2017-04-24 21:35
#

ifeq (/bin/zsh, $(wildcard /bin/zsh))
SHELL		:= /bin/zsh
endif


CC			= clang
NAME		= piscine
CFLAGS		= -Ofast -ffast-math -march=native -mtune=native \
			  -W -Werror -Wextra -Wall -std=c89
CINCS		= -Iinclude
NB_THREAD	= -DNB_THREAD=$(shell nproc)

FILES		= main				\
			  unit_test			\
			  ft_putchar		\
			  ft_print_comb		\
			  ft_print_comb2	\
			  ft_print_combn	\
			  ft_putnbr			

ifeq ($(MAKECMDGOALS),leaks)
CFLAGS		+= -g3
else
CFLAGS		+= -g0
endif

SRC			= $(addsuffix .c, $(FILES))
SRC_PATH	= $(addprefix src/, $(SRC))
OBJ			= $(SRC_PATH:src/%.c=obj/%.o)

T_RESET		= \033[0m
T_TITLE		= $(T_RESET)\033[33;4m
T_DELETE	= $(T_RESET)\033[31;4m
T_FILE		= $(T_RESET)\033[32;3m
T_TEST		= $(T_RESET)\033[33;3m

.PHONY: all clean fclean oclean re dirobj test leaks
.SILENT: all dirobj clean fclean oclean re test leaks

all: dirobj $(NAME)

$(NAME): $(OBJ)
	@echo "\n$(T_TITLE)Compiling binary:$(T_FILE)\t$(shell pwd)/$(NAME)$(T_RESET)\n"
	$(CC) $(NB_THREAD) $(OBJ) -o $(NAME) $(LIBS)
	@echo "\n$(T_TITLE)$(NAME)\t\t\t$(T_FILE)Created$(T_RESET)\n"

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $(CINCS) -o $@ -c $^

clean:
	test ! -d obj ||\
		echo "$(T_DELETE)Delete:$(T_FILE)\t\t\t$(shell pwd)/obj$(T_RESET)" && \
		rm -rf obj

oclean:
	test ! -d outputs || \
		echo "$(T_DELETE)Delete:$(T_FILE)\t\t\t$(shell pwd)/outputs$(T_RESET)" && \
		rm -rf outputs

fclean: clean oclean
	test ! -f $(NAME) || \
		echo "$(T_DELETE)Delete:$(T_FILE)\t\t\t$(shell pwd)/$(NAME)$(T_RESET)" && \
		rm -f $(NAME)

re: fclean all

dirobj:
	test -d obj || \
		echo "$(T_TITLE)Create:$(T_FILE)\t\t\t$(shell pwd)/obj$(T_RESET)" && \
		mkdir -p obj

test: re
	time ./$(NAME) 

leaks: re
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME)
