# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 12:44:28 by nugarcia          #+#    #+#              #
#    Updated: 2023/06/06 11:39:09 by nugarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS_NAME =	main.c\
			get_next_line_utils.c\
			get_next_line.c\
			map.c\
			window.c\
			key_press.c\
			map_check.c\
			path_check.c\
			path_utill.c\
			utills.c\
			img.c

CC = cc
CFLAGS = -Imlx -g
#LDFLAGS = -L /usr/lib/x86_64-linux-gnu
#MILIB = -I /usr/X11/include -g -L /usr/X11/lib -l minilibx -framework OpenGL -framework AppKit
MILIB = -I /usr/X11/include -g -L /usr/X11/lib -l minilibx

MLX_LIB_DIR = mlxlinux/
MLX_INCLUDE = -I mlxlinux/

LMLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -fPIC
RM = rm -rf

HEADER = so_long.h

LIBFT = ./ft_libft/libft.a
LIBFT_PATH = ./ft_libft

INC = -Iincludes -I/usr/include -Imlxlinux


OBJS = $(SRCS_NAME:.c=.o)


all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT) 
		make -s -C mlxlinux/
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INC) $(LMLX_FLAGS) $(MLX_INCLUDE) -o $(NAME)

$(LIBFT):  $(shell make -C $(LIBFT_PATH) -q)
	make  -s -C $(LIBFT_PATH)
	make bonus  -s -C $(LIBFT_PATH)
		$(CC) -c $(CFLAGS) $(LMLX_FLAGS) $(INC) $(MLX_INCLUDE)  $< -o $@

clean:
		make clean -s -C $(LIBFT_PATH)
		rm -rf $(OBJS)

fclean: clean
		make fclean -s -C $(LIBFT_PATH)
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re