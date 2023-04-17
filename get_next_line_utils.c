/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia  <nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:28:03 by nugarcia          #+#    #+#             */
/*   Updated: 2023/04/17 15:28:12 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

int	antioverrite(char *buff)
{
	int	i;
	int	is_nline;
	int	j;

	i = 0;
	j = 0;
	is_nline = 0;
	while (buff[i])
	{
		if (is_nline)
			buff[j++] = buff[i];
		if (buff[i] == '\n')
			is_nline = 1;
		buff[i++] = '\0';
	}
	return (is_nline);
}

char	*ft_strjoin2(char *str1, char *str2)
{
	int		i;
	char	*newstr;

	i = 0;
	newstr = malloc(ft_strlen2(str1) + ft_strlen2(str2) + 1);
	if (!newstr)
		return (NULL);
	while (str1 && str1[i])
	{	
		newstr[i] = str1[i];
		i++;
	}
	free(str1);
	while (*str2)
	{
		newstr[i++] = *str2;
		if (*str2++ == '\n')
			break ;
	}
	newstr[i] = '\0';
	return (newstr);
}
