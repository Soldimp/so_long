/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia  <nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:55:06 by nugarcia          #+#    #+#             */
/*   Updated: 2023/05/17 17:35:46 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//delete sequence of elements of list from a starting point.

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*n;

	n = NULL;
	temp = *lst;
	while (temp)
	{
		n = temp->next;
		del(temp->content);
		free(temp);
		temp = n;
	}
	*lst = NULL;
}
