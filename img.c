/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:03:11 by nugarcia          #+#    #+#             */
/*   Updated: 2023/06/06 10:06:42 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_image	image_make(char *path)
{
	t_image	img;
	int		size;

	img.img = mlx_xpm_file_to_image((*data()).mlx, path,
			&size, &size);
	return (img);
}

t_sp	image_set(void)
{
	static t_sp			spr;
	static int			p;

	if (!p++)
	{
		spr.background = image_make(BACKGROUND);
		spr.collectable = image_make(COLLECTIBLE);
		spr.exit = image_make(EXIT);
		spr.player_down = image_make(PLAYER_DOWN);
		spr.player_left = image_make(PLAYER_LEFT);
		spr.player_right = image_make(PLAYER_RIGHT);
		spr.player_up = image_make(PLAYER_UP);
		spr.wall = image_make(WALL);
	}
	return (spr);
}
