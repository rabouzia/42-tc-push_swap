/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 23:08:07 by rabouzia          #+#    #+#             */
/*   Updated: 2024/03/04 02:50:50 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_value(t_list *a)
{
	int		i;
	int		center;
	t_list	*first;

	center = lst_len(a) / 2;
	first = a;
	i = 0;
	while (a)
	{
		a->index = i;
		if (i <= center)
			a->center = 1;
		if (i > center)
			a->center = 0;
		if (a->next == first)
			break ;
		a = a->next;
		i++;
	}
}

void	find_target(t_list *node_b, t_list *a)
{
	t_list	*first;
	t_list	*target;
	long	value;

	first = a;
	target = a;
	value = LONG_MAX;
	while (a)
	{
		if (a->value > node_b->value && a->value < value)
		{
			value = a->value;
			target = a;
		}
		a = a->next;
		if (a == first)
			break ;
	}
	if (value == LONG_MAX)
		node_b->target = find_smallest(a);
	else
		node_b->target = target;
}

void	get_cost(t_list *a_target, t_list *node_b)
{
	int	cost;
	int	len_a;
	int	len_b;

	cost = 0;
	len_b = lst_len(node_b);
	len_a = lst_len(a_target);
	if (node_b->center && node_b->target->center)
	{
		if (node_b->index > node_b->target->index)
			cost = node_b->index;
		else
			cost = node_b->target->index;
	}
	if (!node_b->center && !node_b->target->center)
	{
		if (len_b - node_b->index > len_a - node_b->target->index)
			cost = len_b - node_b->index;
		else
			cost = len_a - node_b->target->index;
	}
	if (node_b->center && !node_b->target->center)
		cost = len_a - node_b->target->index + node_b->index;
	if (!node_b->center && node_b->target->center)
		cost = node_b->target->index + len_b - node_b->index;
	cost++;
	node_b->cost = cost;
}

void	sniper(t_list *node_b, t_list *a)
{
	t_list	*first;

	first = node_b;
	while (node_b)
	{
		find_target(node_b, a);
		get_cost(node_b->target, node_b);
		node_b = node_b->next;
		if (node_b == first)
			break ;
	}
}

t_list	*get_cheapest(t_list *b)
{
	t_list *cheapest;
	t_list *first;

	first = b;
	if (!b)
		return (NULL);
	cheapest = b;
	while (b)
	{
		if (b->cost < cheapest->cost)
			cheapest = b;
		b = b->next;
		if (b == first)
			break ;
	}
	return (cheapest);
}