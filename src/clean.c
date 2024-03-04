/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 23:08:45 by rabouzia          #+#    #+#             */
/*   Updated: 2024/03/04 03:22:14 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	if (lst)
		free(lst);
}

void	mr_propre(t_list **lst)
{
	t_list	*tmp;
	t_list	*head;

	head = *lst;
	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = tmp;
		if (*lst == head)
			break ;
	}
}
