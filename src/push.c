/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:55:26 by rabouzia          #+#    #+#             */
/*   Updated: 2024/03/03 01:02:11 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	detach_node_head(t_list **head)
{
	t_list	*last;

	if ((*head)->next == *head)
	{
		*head = NULL;
		return ;
	}
	last = (*head)->prev;
	*head = (*head)->next;
	(*head)->prev = (*head)->prev->prev;
	last->next = *head;
}

t_list	*find_last(t_list *lst)
{
	t_list	*first;

	if (!lst)
		return (NULL);
	first = lst;
	while (1)
	{
		if (lst->next == first)
			break ;
		lst = lst->next;
	}
	return (lst);
}

void	push(t_list **t1, t_list **t2)
{
	t_list	*node;
	t_list	*l2;

	if (!t1 || !*t1)
		return ;
	node = *t1;
	detach_node_head(t1);
	if (!*t2)
	{
		(node)->next = node;
		(node)->prev = node;
		*t2 = node;
	}
	else
	{
		l2 = (*t2)->prev;
		l2->next = node;
		node->prev = l2;
		node->next = *t2;
		(*t2)->prev = node;
		(*t2) = node;
	}
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}
