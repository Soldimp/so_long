/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:32:09 by nugarcia          #+#    #+#             */
/*   Updated: 2023/04/05 16:56:15 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>


void	init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 800, 800, "So_Long");
}
int	myclose (t_vars	*va)
{
	printf("here\n");
	mlx_destroy_window(va->mlx, va->win);
	free(va->mlx);
	exit(0);
}

/* int	main(void)
{
	t_vars	vars;
	
	init(&vars);
	//mlx_hook(vars.win, 17, 0, myclose, &vars);
	mlx_loop(vars.win);
}
 */

/* int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
} */