SRC =		src/push.c					\
			src/reverse_rotate.c		\
			src/rotate.c				\
			src/swap.c					\
			src/checking.c				\
			src/filling.c				\
			src/easy_sort.c				\
			src/big_sort.c 				\
			src/turkish.c				\
			src/mini_libft.c			\
			src/clean.c					\
			src/ft_split.c				\
			src/main.c						


BONUS_SRC =	src/checker.c				\
			src/get_next_line.c 		\
			src/get_next_line_utils.c 	\
			src/filling.c				\
			src/checking.c				\
			src/push.c					\
			src/reverse_rotate.c		\
			src/rotate.c				\
			src/mini_libft.c			\
			src/swap.c					\
			src/ft_split.c				\
			src/clean.c 				\
			src/easy_sort.c				\
			src/checker_op1.c			\
			src/checker_op2.c			\
			src/checker_utils.c			



NAME =		push_swap

BONUS_NAME = checker

CFLAGS =	-Wall -Werror -Wextra -g3 -I./inc

CC =		cc

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all:		$(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $@ $^

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
		$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
		rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: clean fclean all re bonus
