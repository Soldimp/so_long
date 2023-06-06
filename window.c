/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:46:46 by nugarcia          #+#    #+#             */
/*   Updated: 2023/06/06 11:02:40 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	window_set_tile(char **map, int key, int x, int y)
{
	if (map[y][x] == '1')
		mlx_put_image_to_window((*data()).mlx, (*data()).win,
			image_set().wall.img, x * IMG_W, y * IMG_H);
	else if (map[y][x] == '0')
		mlx_put_image_to_window((*data()).mlx, (*data()).win,
			image_set().background.img, x * IMG_W, y * IMG_H);
	else if (map[y][x] == 'P')
		mlx_put_image_to_window((*data()).mlx, (*data()).win,
			player_key(key), x * IMG_W, y * IMG_H);
	else if (map[y][x] == 'C')
		mlx_put_image_to_window((*data()).mlx, (*data()).win,
			image_set().collectable.img, x * IMG_W, y * IMG_H);
	else if (map[y][x] == 'E')
		mlx_put_image_to_window((*data()).mlx, (*data()).win,
			image_set().exit.img, x * IMG_W, y * IMG_H);
}

void	window_load(char **map, int key, int p, int i)
{
	while (map[p])
	{
		i = 0;
		while (map[p][i])
		{
			window_set_tile(map, key, i, p);
			i++;
		}
		p++;
	}
}

void	window_create(char **map, char **av)
{
	(*data()).win_x = map_size(map, 'x');
	(*data()).win_y = map_size(map, 'y');
	(*data()).mlx = mlx_init();
	(*data()).win = mlx_new_window((*data()).mlx, (*data()).win_x * IMG_W,
			(*data()).win_y * IMG_H, "So Long");
	window_load(map, KEY_UP, 0, 0);
	mlx_hook((*data()).win, 2, 1L << 0, key_press, map);
	mlx_hook((*data()).win, 17, 0L, close_window, map);
	mlx_loop((*data()).mlx);
}
