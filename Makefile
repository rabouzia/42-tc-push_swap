
SRC =		parsing/check_mon_pote.c	\
		parsing/fillupthetank.c			\
		sorting/easy_sort.c				\
		sorting/big_sort.c 				\
		sorting/turkish.c				\
		sorting/big_sort.c				\
		tools/mini_libft.c				\
		tools/clean.c					\
		operators/push.c				\
		operators/reverse_rotate.c		\
		operators/rotate.c				\
		operators/swap.c				\
		printing/ft_printf.c			\
		printing/utils.c				\
		main.c 							\


NAME = push_swap

CFLAGS = -Wall -Werror -Wextra -g3 -I./

CC = gcc

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
		$(CC) -o $@ $^

$(%.o): $(%.c)
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
