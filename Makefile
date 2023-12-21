SRCS = 

NAME = 

CC = gcc

FLAGS = -c -Wall -Wextra -Wall

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
		ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
		rm -rf $(SURPL_O)
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all