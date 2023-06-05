/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia  <nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:32:09 by nugarcia          #+#    #+#             */
/*   Updated: 2023/05/30 16:10:45 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

int	close_window(char **map)
{
	int p;

	p = 0;
	mlx_clear_window((*data()).mlx, (*data()).win);
	mlx_destroy_image((*data()).mlx, image_set().exit.img);
	mlx_destroy_image((*data()).mlx, image_set().player_up.img);
	mlx_destroy_image((*data()).mlx, image_set().player_down.img);
	mlx_destroy_image((*data()).mlx, image_set().player_left.img);
	mlx_destroy_image((*data()).mlx, image_set().player_right.img);
	mlx_destroy_image((*data()).mlx, image_set().background.img);
	mlx_destroy_image((*data()).mlx, image_set().wall.img);
	mlx_destroy_image((*data()).mlx, image_set().collectable.img);
	mlx_destroy_window((*data()).mlx, (*data()).win);
	while (map[p])
		free(map[p++]);
	free(map);
	mlx_destroy_display((*data()).mlx);
	free((*data()).mlx);
	exit(0);
}


void	print_error(char *msg, char **map)
{
	int	p;
	
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	p = 0;
	if (map)
	{
		while (map[p])
			free(map[p++]);
		free(map);
	}
	exit(1);
}

int main(int ac, char **av)
{
    char	**map;
	t_list	*map_list;

	map = 0;
	map_list = 0;
	if (ac != 2)
		print_error("Select one map/only one Map", 0);
	(*data()).moves = 0;
	map = map_matrix(av[1], map_list);
	checkmap(map);
	window_create(map, av);
	ft_lstclear(&map_list, free);
    return (0);
}
