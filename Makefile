NAME      = fractol

CC        = cc
CFLAGS    = -Wall -Wextra -Werror


SRCS      = main.c utils.c

OBJS      =$(SRCS:.c=.o)


all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re
