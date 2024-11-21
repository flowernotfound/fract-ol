# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 05:09:10 by hmitsuyo          #+#    #+#              #
#    Updated: 2024/11/21 21:26:41 by hiroaki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_itoa.c \
       ft_print_char.c \
       ft_print_hex.c \
       ft_print_int.c \
       ft_print_ptr.c \
       ft_print_str.c \
       ft_print_unsigned.c \
       ft_printf.c \
       ft_utils.c \
       ft_utoa.c \
       ft_strcmp.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
