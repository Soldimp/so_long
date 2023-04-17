/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia  <nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:16:22 by nugarcia          #+#    #+#             */
/*   Updated: 2023/04/17 15:58:54 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_line_length(int fd)
{
	char	buffer[1];
	int		length;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	length = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			length++;
		else
			break ;
	}
	return (length);
}

static	void	exit_error(void)
{
	printf("Error\nwrong map dimensions\n");
	exit(EXIT_FAILURE);
}

int	ft_count_lines(int fd, int x, int img_w)
{
	char	*line;
	int		linecount;
	int		i;

	i = 0;
	linecount = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if ((int)ft_strlen(line) < x / img_w
			|| (ft_strlen(line) == 1 && *line != '\n'))
		{
			free(line);
			exit_error();
		}
		else
		{
			free(line);
			linecount++;
		}
	}
	return (linecount);
}