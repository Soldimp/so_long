/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:11:20 by nugarcia          #+#    #+#             */
/*   Updated: 2023/06/06 12:04:43 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (ft_strnstr(path, ".ber", ft_strlen(path)) == NULL)
	{
		print_error("map has to be .ber", 0);
		exit(0);
	}
	if (fd < 0)
	{
		print_error("Invalid map_path/map", 0);
		exit(0);
	}
	return (open(path, O_RDONLY));
}

static t_list	*map_get(char *av)
{
	int		fd;
	t_list	*map;
	char	*line;

	fd = map_open(av);
	map = 0;
	if (fd == -1)
		print_error("Failed to read map.", 0);
	line = get_next_line(fd);
	if (!line)
		print_error("provided map is empty.", 0);
	while (line)
	{
		ft_lstadd_back(&map, ft_lstnew(line));
		line = get_next_line(fd);
	}
	free(line);
	return (map);
}

char	**map_matrix(char *path, t_list *cursor)
{
	int		p;
	char	**res;
	t_list	*map;

	p = 0;
	map = map_get(path);
	cursor = map;
	while (cursor)
	{
		p++;
		cursor = cursor->next;
	}
	res = malloc((p + 1) * sizeof(char *));
	if (!res)
		return (0);
	cursor = map;
	p = 0;
	while (cursor)
	{
		res[p++] = cursor->content;
		cursor = cursor->next;
	}
	res[p] = NULL;
	ft_lstclear2(&map);
	return (res);
}

int	map_size(char **map, char axis)
{
	int	p;

	p = 0;
	if (axis == 'x')
		p = ft_strlen(map[0]);
	else if (axis == 'y')
	{
		while (map[p])
			p++;
	}
	return (p);
}

void	map_update(char **map, int key, int x, int y)
{
	if (map[y][x] == 'E')
	{
		ft_printf("Game won!!\n");
		close_window(map);
	}
	map[y][x] = 'P';
	window_load(map, key, 0, 0);
	(*data)()->moves++;
	display_move((*data)()->moves);
	nor_update(key);
}
