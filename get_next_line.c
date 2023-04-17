/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia  <nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:27:30 by nugarcia          #+#    #+#             */
/*   Updated: 2023/04/17 15:27:44 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		while (stash[i])
			stash[i++] = 0;
		return (NULL);
	}	
	line = NULL;
	while (stash[0] || read(fd, stash, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin2(line, stash);
		if (antioverrite(stash))
			break ;
	}
	return (line);
}

/* int main()
{
	int fd = 0;
	char *line;
	fd = open("./fd.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
	}
	free(line);
	close(fd);

} */
