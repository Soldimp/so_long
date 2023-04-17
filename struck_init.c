/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struck_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia  <nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:33:35 by nugarcia          #+#    #+#             */
/*   Updated: 2023/04/17 16:25:39 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_data *data, t_map *map)
{
	char	*relative_path;
	int		img_width;
	int		img_height;
	t_img	*img;

	data->map = map;
	img_width = 0;
	img_height = 0;
	img = malloc(sizeof(t_img));
	if (!img)
	{
		printf("Error\nmalloc failed\n");
		exit(0);
	}

	data->img = img;
	relative_path = "images/ship_up.xpm";
	data->img->player_up = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	relative_path = "./images/ship_left.xpm";
	data->img->player_left = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	relative_path = "./images/ship_down.xpm";
	data->img->player_down = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	data->counter = 0;
	data->collected = 0;
}