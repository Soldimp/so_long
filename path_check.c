/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:29:54 by nugarcia          #+#    #+#             */
/*   Updated: 2023/06/06 10:55:19 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_collet(char **map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			if (map[y][x++] == 'C')
				count++;
		y++;
	}
	return (count);
}

static void	find_path_collet(char **tmp, int x, int y)
{
	tmp[y][x] = 'V';
	if (tmp[y][x + 1] != '1' && tmp[y][x + 1] != 'V' && tmp[y][x + 1] != 'E')
		find_path_collet(tmp, x + 1, y);
	if (tmp[y][x - 1] != '1' && tmp[y][x - 1] != 'V' && tmp[y][x - 1] != 'E')
		find_path_collet(tmp, x - 1, y);
	if (tmp[y + 1][x] != '1' && tmp[y + 1][x] != 'V' && tmp[y + 1][x] != 'E')
		find_path_collet(tmp, x, y + 1);
	if (tmp[y - 1][x] != '1' && tmp[y - 1][x] != 'V' && tmp[y - 1][x] != 'E')
		find_path_collet(tmp, x, y - 1);
}

static int	find_path_exit(char **tmp, int x, int y)
{
	static int	exit;

	if (tmp[y][x] == 'E')
		exit++;
	tmp[y][x] = 'V';
	if (tmp[y][x + 1] != '1' && tmp[y][x + 1] != 'V')
		find_path_exit(tmp, x + 1, y);
	if (tmp[y][x - 1] != '1' && tmp[y][x - 1] != 'V')
		find_path_exit(tmp, x - 1, y);
	if (tmp[y + 1][x] != '1' && tmp[y + 1][x] != 'V')
		find_path_exit(tmp, x, y + 1);
	if (tmp[y - 1][x] != '1' && tmp[y - 1][x] != 'V')
		find_path_exit(tmp, x, y - 1);
	return (exit);
}

void	check_path(char **map, int x, int y)
{
	char	**tmp;
	int		collet;
	int		valid;

	tmp = dup_matrix(map);
	if (!tmp)
		return ;
	find_path_collet(tmp, x, y);
	collet = count_collet(tmp);
	free_matrix(tmp);
	tmp = dup_matrix(map);
	valid = (find_path_exit(tmp, x, y) && !collet);
	free_matrix(tmp);
	if (!valid)
		print_error("provided map does not contain a valid path.", map);
}
