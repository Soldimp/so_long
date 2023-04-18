/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:11:20 by nugarcia          #+#    #+#             */
/*   Updated: 2023/04/18 17:15:48 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_size(t_data *data, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nInvalid map_path/map\n");
		exit(0);
	}
	if (ft_strnstr(av[1], ".ber", ft_strlen(av[1])) == NULL)
	{
		printf("Error\nmap has to be .ber\n");
		exit(0);
	}
	data->win_x = (ft_line_length(fd) * IMG_W);
	data->win_y = (ft_count_lines(fd, data->win_x, IMG_W) * IMG_H);
	printf("win x: %d\n", data->win_x);
	printf("win y: %d\n", data->win_y);
}

void	creat_map(t_data *data, t_map *map)
{
	map->map = ft_calloc(data->win_y + 1, sizeof(char **));
	map->x = 0;
	map->y = 0;
	while (map->y < (data->win_y / IMG_H))
	{
		if (map->y == 'P' && map->x == 'P')
			put_player(data);
		
		if (map->x < (data->win_x / IMG_W))
			map->x++;
		else
		{
			map->y++;
			map->x = 0;
		}
	}
}
