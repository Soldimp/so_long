/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:32:50 by nugarcia          #+#    #+#             */
/*   Updated: 2023/04/11 13:13:39 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "ft_libft/libft.h"
# include "mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <stdio.h>
# include <math.h>
# include <string.h>

# define IMG_W 32
# define IMG_H 32

/* typedef struct	s_vars {
void	*mlx;
void	*win;
void	*img;
int		img_width;
int		img_height;
}			t_vars;
 */

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
	int		p_x;
	int		p_y;
	int		counter;
	int		collected;
	void	*img;
	t_map	*map;
}				t_data;



int	main();

#endif