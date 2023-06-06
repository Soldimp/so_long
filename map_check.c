/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:55:24 by nugarcia          #+#    #+#             */
/*   Updated: 2023/06/06 10:51:13 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	rect_or_no(char **map, int y, int x)
{
	x = ft_strlen(map[0]);
	while (map[y])
		if (ft_strlen(map[y++]) != x)
			print_error("Map is not rectangular.", map);
	if (y < 3 || x - 1 < 3)
		print_error("Map is too small.", map);
}

static	void	is_map_surrounded(char **map, int y, int x)
{
	while (map[y][x] && map[y][x] != '\n')
		if (map[y][x++] != '1')
			print_error("provided map not surrounded by walls.", map);
	y++;
	while (map[y])
	{
		x = ft_strlen(map[y]) - 2;
		if (map[y][0] != '1' || map[y][x] != '1')
			print_error("provided map not surrounded by walls.", map);
		y++;
	}
	y--;
	x = 0;
	while (map[y][x] && map[y][x] != '\n')
		if (map[y][x++] != '1')
			print_error("provided map not surrounded by walls.", map);
}

static void	check_starting_pos(char **map, int player, int exit, int collet)
{
	if (player == 0)
		print_error("No player exist.", map);
	else if (player > 1)
		print_error("SINGLE PLAYER ONLY!!", map);
	if (exit == 0)
		print_error("No exit.", map);
	else if (exit > 1)
		print_error("Only need 1 exit.", map);
	if (collet == 0)
		print_error("No collectables", map);
}

static void	check_other(char **map, int y, int x)
{
	int	player;
	int	exit;
	int	collet;

	player = 0;
	exit = 0;
	collet = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				player++;
			else if (map[y][x] == 'E')
				exit++;
			else if (map[y][x] == 'C')
				collet++;
			else if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != '\n')
				print_error("invalid object detected in map.", map);
			x++;
		}
		y++;
	}
	check_starting_pos(map, player, exit, collet);
}

void	checkmap(char **map)
{
	rect_or_no(map, 1, 0);
	is_map_surrounded(map, 0, 0);
	check_other(map, 1, 0);
	check_path(map, get_player_pos(map).x, get_player_pos(map).y);
}
