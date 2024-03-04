
SRC =		src/push.c				\
		src/reverse_rotate.c		\
		src/rotate.c				\
		src/swap.c					\
		src/checking.c				\
		src/filling.c				\
		src/easy_sort.c				\
		src/big_sort.c 				\
		src/turkish.c				\
		src/big_sort.c				\
		src/mini_libft.c			\
		src/clean.c					\
		src/main.c 					\


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
