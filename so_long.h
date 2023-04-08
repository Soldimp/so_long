/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia  <nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:32:50 by nugarcia          #+#    #+#             */
/*   Updated: 2023/04/08 15:11:05 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "mlx_linux/mlx.h"
# include <X11/keysym.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	main();

#endif