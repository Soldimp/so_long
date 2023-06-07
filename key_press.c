/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:22:03 by nugarcia          #+#    #+#             */
/*   Updated: 2023/06/07 11:05:38 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*player_key(int key)
{
	static void	*img;

	if (key == XK_s || !img)
		img = image_set().player_down.img;
	else if (key == XK_w)
		img = image_set().player_up.img;
	else if (key == XK_a)
		img = image_set().player_left.img;
	else if (key == XK_d)
		img = image_set().player_right.img;
	return (img);
}

t_pos	get_player_pos(char **map)
{
	int		y;
	int		x;
	t_pos	player_pos;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				player_pos.x = x;
				player_pos.y = y;
				break ;
			}
			x++;
		}
		if (map[y][x] == 'P')
			break ;
		y++;
	}
	return (player_pos);
}

static int	player_collision(char **map, int x, int y)
{
	int	p;
	int	i;
	int	collet;

	p = 0;
	collet = 0;
	while (map[p])
	{
		i = 0;
		while (map[p][i])
			if (map[p][i++] == 'C')
				collet++;
		p++;
	}
	if (map[y][x] == '1')
		return (1);
	else if (map[y][x] == 'E' && collet)
		return (1);
	return (0);
}

int	key_press(int key, char **map)
{
	t_pos		pos;

	pos = get_player_pos(map);
	map[pos.y][pos.x] = '0';
	if (key == XK_w && !player_collision(map, pos.x, pos.y - 1))
		map_update(map, key, pos.x, pos.y - 1);
	else if (key == XK_s && !player_collision(map, pos.x, pos.y + 1))
		map_update(map, key, pos.x, pos.y + 1);
	else if (key == XK_a && !player_collision(map, pos.x - 1, pos.y))
		map_update(map, key, pos.x - 1, pos.y);
	else if (key == XK_d && !player_collision(map, pos.x + 1, pos.y))
		map_update(map, key, pos.x + 1, pos.y);
	else if (key == XK_Escape)
	{
		ft_printf("Game Closed\n");
		close_window(map);
	}
	else
		map[pos.y][pos.x] = 'P';
	return (0);
}
