CC = gcc
# CFLAGS = -Wall -Wextra -Werror -I./minilibx-linux
CFLAGS = -I./minilibx-linux
SRC = ./src/main.c ./src/event.c ./src/color.c
OBJ = $(SRC:.c=.o)
NAME = fract-ol

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L/usr/X11R6/lib -lmlx -lX11 -lXext -framework OpenGL -framework AppKit -g -fsanitize=address -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@echo "Object files removed."

fclean: clean
	rm -f $(NAME)
	@echo "Executable removed."

re: fclean all

.PHONY: all clean fclean re
