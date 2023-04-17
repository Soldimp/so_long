/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia  <nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:11:20 by nugarcia          #+#    #+#             */
/*   Updated: 2023/04/17 15:58:12 by nugarcia         ###   ########.fr       */
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
}

void	creat_map(t_data *data)
{
	data->map->x = 0;
	data->map->y = 0;
	while (data->map->y < (data->win_y / IMG_H))
	{
		if (data->map->map[data->map->y][data->map->x] == 'P')
			put_player(data);
		else if (data->map->map[data->map->y][data->map->x] == '1')
			put_object(data, "./images/wall.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'C')
			put_object(data, "./images/collectable.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'E')
			put_object(data, "./images/exit.xpm");
		if (data->map->x < (data->win_x / IMG_W))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}
