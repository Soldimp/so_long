# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 12:44:28 by nugarcia          #+#    #+#              #
#    Updated: 2023/04/05 13:00:41 by nugarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS_NAME =	test.c

CC = cc
CFLAGS = -Wall -Werror -Wextra -Imlx -g -fsanitize=address
MILIB = -I /usr/X11/include -g -L /usr/X11/lib -l minilibx -framework OpenGL -framework AppKit

MLX_LIB_DIR = mlx_linux/
MLX_INCLUDE = -I mlx_linux/

LMLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -fPIC
RM = rm -rf

#HEADER = so_long.h

#FT_PRINTF = ./ft_printf/libftprintf.a
#FT_PRINTF_PATH = ./ft_printf

#LIBFT = ./libft/libft.a
#LIBFT_PATH = ./libft

INC = -Iincludes -I/usr/include -Imlx_linux

#SRC_PATH = ./src

#OBJ_PATH = ./objects

OBJS = $(SRCS_NAME:.c=.o)

#SRC = $(addprefix $(SRC_PATH)/, $(SRCS_NAME))

all: $(NAME)

$(NAME) : $(OBJS) #$(FT_PRINTF) $(LIBFT) $(OBJS)
		make -s -C mlx_linux/
#		$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) $(LIBFT) $(INC) $(LMLX_FLAGS) $(MLX_INCLUDE) -o $(NAME)
		$(CC) $(CFLAGS) $(OBJS) $(INC) $(LMLX_FLAGS) $(MLX_INCLUDE) -o $(NAME)
#$(FT_PRINTF): $(shell make -C $(FT_PRINTF_PATH) -q)
#make -C$(FT_PRINTF_PATH)

#$(LIBFT):  $(shell make -C $(LIBFT_PATH) -q)
#make -C$(LIBFT_PATH)

#$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c $(MLX_LIB)
#	mkdir -p objects
	$(CC) -c $(CFLAGS) $(LMLX_FLAGS) $(INC) $(MLX_INCLUDE)  $< -o $@

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re