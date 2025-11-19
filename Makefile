NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux
SRC = main.c mandelbrot.c julia.c utils.c moves.c coloring.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lminilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
