/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:22:03 by nugarcia          #+#    #+#             */
/*   Updated: 2023/06/06 11:09:10 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*player_key(int key)
{
	static void	*img;

	if (key == KEY_DOWN || !img)
		img = image_set().player_down.img;
	else if (key == KEY_UP)
		img = image_set().player_up.img;
	else if (key == KEY_LEFT)
		img = image_set().player_left.img;
	else if (key == KEY_RIGHT)
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

void	nor_update(int key)
{
	if (key == KEY_UP)
		printf("moved: %d\n", (*data)()->moves);
	else if (key == KEY_DOWN)
		printf("moved: %d\n", (*data)()->moves);
	else if (key == KEY_LEFT)
		printf("moved: %d\n", (*data)()->moves);
	else if (key == KEY_RIGHT)
		printf("moved: %d\n", (*data)()->moves);
}

int	key_press(int key, char **map)
{
	t_pos		pos;

	pos = get_player_pos(map);
	map[pos.y][pos.x] = '0';
	if (key == KEY_UP && !player_collision(map, pos.x, pos.y - 1))
		map_update(map, key, pos.x, pos.y - 1);
	else if (key == KEY_DOWN && !player_collision(map, pos.x, pos.y + 1))
		map_update(map, key, pos.x, pos.y + 1);
	else if (key == KEY_LEFT && !player_collision(map, pos.x - 1, pos.y))
		map_update(map, key, pos.x - 1, pos.y);
	else if (key == KEY_RIGHT && !player_collision(map, pos.x + 1, pos.y))
		map_update(map, key, pos.x + 1, pos.y);
	else if (key == KEY_ESC)
	{
		ft_putstr_fd("Game Closed\n", 1);
		close_window(map);
	}
	else
		map[pos.y][pos.x] = 'P';
	nor_update(key);
	return (0);
}
