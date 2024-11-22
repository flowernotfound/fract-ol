CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LDFLAGS = -fsanitize=address
LIBFT_PATH = inc/libft
MLX_PATH = minilibx-linux
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
SRC_FILES = main.c events.c color.c init.c julia.c key.c mandelbrot.c \
           mouse.c tricorn.c utils.c parse_args.c parse_julia.c atof.c \
           process_input.c zoom.c move.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
LIBFT = $(LIBFT_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx_Linux.a
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    MLX_FLAGS = -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
else
    MLX_FLAGS = -L/usr/X11R6/lib -lmlx -lX11 -lXext -framework OpenGL -framework AppKit
endif

NAME = fractol

all: $(NAME)

$(MLX):
	@$(MAKE) -C $(MLX_PATH)
	@echo "Compiled MLX"

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(OBJ) $(LDFLAGS) -L$(LIBFT_PATH) -lft $(MLX_FLAGS) -o $(NAME)
	@echo "Executable $(NAME) created"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "Created object directory"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_PATH) -I$(MLX_PATH) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)
	@echo "Compiled libft"

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean
	rm -rf $(OBJ_DIR)
	@echo "Cleaned object files"

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)
	@echo "Cleaned everything"

re: fclean all

.PHONY: all clean fclean re
