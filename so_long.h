/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia  <nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:32:50 by nugarcia          #+#    #+#             */
/*   Updated: 2023/05/30 16:10:57 by nugarcia         ###   ########.fr       */
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
# include <stdbool.h>

# define IMG_W 32
# define IMG_H 32

# define PLAYER_UP "images/ship_up.xpm"
# define PLAYER_DOWN "images/ship_down.xpm"
# define PLAYER_LEFT "images/ship_left.xpm"
# define PLAYER_RIGHT "images/ship_right.xpm"
# define WALL "images/wall.xpm"
# define BACKGROUND "images/background.xpm"
# define COLLECTIBLE "images/collectable.xpm"
# define EXIT "images/exit.xpm"

# define KEY_UP XK_w 
# define KEY_DOWN XK_s
# define KEY_LEFT XK_a
# define KEY_RIGHT XK_d
# define KEY_ESC XK_Escape

/********************** GNL **********************************/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
size_t	ft_strlen2(char *str);
char	*ft_strjoin2(char *s1, char *s2);
int		antioverrite(char *stash);

/********************** STRUCS **********************************/

typedef struct s_image
{
	void	*img;
}				t_image;

typedef struct s_sp
{
	t_image	player_up;
	t_image	player_left;
	t_image	player_right;
	t_image	player_down;
	t_image	exit;
	t_image	background;
	t_image	wall;
	t_image	collectable;
}				t_sp;

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;


typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		win_x;
	int		win_y;
	int		moves;
}				t_data;

/********************** FUNCTIONS **********************************/
int				close_window(char **map);
t_data			*data(void);
void			print_error(char *msg, char **map);
/********************** KEYPRESS **********************************/
void			*player_key(int key);
int				key_press(int keycode, char **map);
void			*collect_exit(char **map);
t_pos			get_player_pos(char **map);
/********************** WINDOW **********************************/
void			window_create(char **map, char **av);
void			window_load(char **map, int key, int p, int i);

/********************** MAP **********************************/
void 			display_map(t_data *data, char **map);
char			**map_matrix(char *path, t_list *map_ber);
int				map_size(char **map, char axis);
void			map_update(char **map, int key, int x, int y);
void 			checkmap(char **map);
void			check_path(char **map, int x, int y);
/********************** IMG **********************************/
t_sp			image_set(void);

#endif