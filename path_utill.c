/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:54:20 by nugarcia          #+#    #+#             */
/*   Updated: 2023/06/06 11:00:24 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**dup_matrix(char **matrix)
{
	char	**res;
	int		p;

	p = 0;
	while (matrix[p])
		p++;
	res = malloc((p + 1) * sizeof(char *));
	res[p] = NULL;
	p = 0;
	while (matrix[p])
	{
		res[p] = ft_strdup(matrix[p]);
		p++;
	}
	return (res);
}

void	free_matrix(char **matrix)
{
	int	p;

	p = 0;
	while (matrix[p])
		free(matrix[p++]);
	free(matrix);
}
