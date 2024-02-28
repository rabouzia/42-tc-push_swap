/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:55:26 by rabouzia          #+#    #+#             */
/*   Updated: 2024/02/18 20:21:08 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_node_head(t_list **head)
{
	t_list	*last;
	t_list	*temp;

	if (!head || !*head)
		return ;
	temp = (*head);
	if ((*head)->next == *head)
	{
		free(*head);
		*head = NULL;
		return ;
	}
	last = (*head)->prev;
	*head = (*head)->next;
	(*head)->prev = (*head)->prev->prev;
	last->next = *head;
	free(temp);
}

void	push(t_list **t1, t_list **t2)
{
	int		ti;
	t_list	*new_node;
	t_list	*l2;

	if (!t1 || !*t1)
		return ;
	ti = (*t1)->value;
	delete_node_head(t1);
	new_node = create_node(ti);
	if (!*t2)
	{
		*t2 = new_node;
		(*t2)->next = *t2;
		(*t2)->prev = *t2;
	}
	else
	{
		l2 = (*t2)->prev;
		l2->next = new_node;
		new_node->prev = l2;
		new_node->next = *t2;
		(*t2) = new_node;
	}
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
