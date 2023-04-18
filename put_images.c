/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:46:46 by nugarcia          #+#    #+#             */
/*   Updated: 2023/04/18 16:52:53 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_background(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->win_y)
	{
		x = 0;
		while (x < data->win_x)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->img->background, x, y);
			x += IMG_W;
		}
		y += IMG_H;
	}
}

void	put_object(t_data *data, char *relative_path)
{
	int		img_width;
	int		img_height;

	img_height = data->pos_y;
	img_width = data->pos_x;
	data->map->object = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->win, data->map->object,
		(data->map->x * IMG_W), (data->map->y * IMG_H));
}

void	put_player(t_data *data)
{
	data->pos_x = data->map->x;
	data->pos_y = data->map->y;
	mlx_put_image_to_window(data->mlx, data->win, data->img->player_up,
		(data->pos_x * IMG_W), (data->pos_y * IMG_H));
}