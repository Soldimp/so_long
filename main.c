/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia  <nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:32:09 by nugarcia          #+#    #+#             */
/*   Updated: 2023/04/17 15:53:43 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	main(int ac, char **av)
{
	t_data	data;
	t_map	map;

	window_size(&data, av);
	map.map = ft_calloc(data.win_y + 1,sizeof(char *));
	if (!map.map)
	{
		printf("Error\ncalloc failed\n");
		exit(0);
	}
	init(&data, &map);
	/*inputs_errors(&data, av, ac)*/
	put_background(&data);
	creat_map(&data);
	mlx_hook(data.win, 2, 1L<<0, key_press, &data);
	mlx_hook(data.win, 17, 0L, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}

