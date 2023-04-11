/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:32:09 by nugarcia          #+#    #+#             */
/*   Updated: 2023/04/11 13:13:20 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_data *data)
{
	
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1200, 1200, "So_Long");
	data->counter = 0;
	data->img = mlx_xpm_file_to_image(data->mlx, "1.xpm", &data->p_x, &data->p_y);
	
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}
	
int	key_press(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		close_window(data);
	}

	if (keycode == XK_w || keycode == XK_s || keycode == XK_a || keycode == XK_d ||
	    keycode == XK_Up || keycode == XK_Down || keycode == XK_Left || keycode == XK_Right)
	{
		++data->counter;
	}
	printf("You moved %d\n", data->counter);
	char *move_counter = ft_itoa(data->counter);
	mlx_string_put(data->mlx, data->win, 10, 100,  0xFFFFFF, move_counter);
	free(move_counter);
	return (0);
}

int	main(void)
{
	t_data	data;

	init(&data);
	mlx_hook(data.win, 2, 1L<<0, key_press, &data);
	mlx_hook(data.win, 17, 0L, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}

