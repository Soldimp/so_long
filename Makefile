# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 12:44:28 by nugarcia          #+#    #+#              #
#    Updated: 2023/04/11 16:03:47 by nugarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS_NAME =	main.c

CC = cc
CFLAGS = -Imlx -g -fsanitize=address
MILIB = -I /usr/X11/include -g -L /usr/X11/lib -l minilibx -framework OpenGL -framework AppKit

MLX_LIB_DIR = mlxlinux/
MLX_INCLUDE = -I mlxlinux/

LMLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -fPIC
RM = rm -rf

HEADER = so_long.h

#FT_PRINTF = ./ft_printf/libftprintf.a
#FT_PRINTF_PATH = ./ft_printf

LIBFT = ./ft_libft/libft.a
LIBFT_PATH = ./ft_libft

INC = -Iincludes -I/usr/include -Imlxlinux


OBJS = $(SRCS_NAME:.c=.o)


all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT) 
		make -s -C mlxlinux/
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INC) $(LMLX_FLAGS) $(MLX_INCLUDE) -o $(NAME)

$(LIBFT):  $(shell make -C $(LIBFT_PATH) -q)
	make -s -C $(LIBFT_PATH)

		$(CC) -c $(CFLAGS) $(LMLX_FLAGS) $(INC) $(MLX_INCLUDE)  $< -o $@

clean:
		make clean -s -C $(LIBFT_PATH)
		rm -rf $(OBJS)

fclean: clean
		make fclean -s -C $(LIBFT_PATH)
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re