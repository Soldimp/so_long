/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:33:35 by nugarcia          #+#    #+#             */
/*   Updated: 2023/06/07 11:04:07 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lstdelone2(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ft_lstclear2(t_list **lst)
{
	t_list	*hold;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		hold = (*lst)->next;
		ft_lstdelone2(*lst);
		*lst = hold;
	}
	lst = 0;
}

void	print_onscreen(char *msg, int x, int y)
{
	mlx_string_put((*data()).mlx, (*data()).win, x, y, 0xFFFFFF, msg);
}

void	display_move(int move)
{
	char	*tmp_join;
	char	*tmp_itoa;

	tmp_itoa = ft_itoa(move);
	tmp_join = ft_strjoin("Moves: ", tmp_itoa);
	print_onscreen(tmp_join, 4, 16);
	free(tmp_itoa);
	free(tmp_join);
}

void	nor_update(int key)
{
	if (key == XK_w)
		ft_printf("moved: %d\n", (*data)()->moves);
	else if (key == XK_s)
		ft_printf("moved: %d\n", (*data)()->moves);
	else if (key == XK_a)
		ft_printf("moved: %d\n", (*data)()->moves);
	else if (key == XK_d)
		ft_printf("moved: %d\n", (*data)()->moves);
}
