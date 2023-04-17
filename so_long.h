/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia  <nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:32:50 by nugarcia          #+#    #+#             */
/*   Updated: 2023/04/17 15:59:06 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "ft_libft/libft.h"
# include "mlxlinux/mlx.h"
# include <X11/keysym.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# define IMG_W 32
# define IMG_H 32

/********************** GNL **********************************/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
size_t	ft_strlen2(char *str);
char	*ft_strjoin2(char *s1, char *s2);
int		antioverrite(char *stash);

/********************** STRUCS **********************************/

typedef struct s_img
{
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*background;
}				t_img;


typedef struct s_map
{
	char	**map;
	void	*object;
	int		x;
	int		y;
	int		coins;
}				t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		win_x;
	int		win_y;
	int		pos_x;
	int		pos_y;
	int		counter;
	int		collected;
	t_img	*img;
	t_map	*map;
}				t_data;
/********************** FUNTIONS **********************************/
void	init(t_data *data, t_map *map);
int		close_window(t_data *data);

/********************** KEYPRESS **********************************/
int		key_press(int keycode, t_data *data);

/********************** MAP **********************************/
void	window_size(t_data *data, char **av);
void	creat_map(t_data *data);
int		ft_line_length(int fd);
int		ft_count_lines(int fd, int x, int img_w);

/********************** IMG **********************************/
void	put_background(t_data *data);
void	put_player(t_data *data);
void	put_object(t_data *data, char *relative_path);

#endif