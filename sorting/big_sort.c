/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 23:08:07 by rabouzia          #+#    #+#             */
/*   Updated: 2024/02/28 22:40:16 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_biggest(t_list *a)
{
	t_list	*biggest;
	t_list	*first;

	first = a;
	if (!a)
		return (NULL);
	biggest = a;
	while (a)
	{
		a = a->next;
		if (a->value > biggest->value)
			biggest = a;
		if (a->next == first)
			break ;
	}
	return (biggest);
}

t_list	*find_smallest(t_list *a)
{
	t_list	*smallest;
	t_list	*first;

	first = a;
	if (!a)
		return (NULL);
	smallest = a;
	while (a)
	{
		if (a == first)
			break ;
		if (a->value < smallest->value)
			smallest = a;
		a = a->next;
	}
	return (smallest);
}

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
	t_list	*t;
	int		i;
	t_list	*tmp;

	tmp = a;
	i = 0;
	t = a;
	while (a)
	{
		if (a->value > node_b->value && (a->value < t->value
				|| t->value <= node_b->value))
		{
			t = a;
			i = 1;
		}
		a = a->next;
		if (a == tmp)
			break ;
		printf("find_target\n");
	}
	if (!i)
		node_b->target = find_smallest(a);
	node_b->target = t;
}

void	get_cost(t_list *a_target, t_list *node_b)
{
	int	cost;
	int	len_b;

	cost = 0;
	len_b = lst_len(node_b);
	find_target(node_b, a_target);
	if (node_b->center)
		cost = (node_b->target->index + node_b->index);
	else
		cost = (node_b->target->index) + (len_b - node_b->index);
	cost++; // le push
	node_b->cost = cost;
}
/*
	// printf("\n");
	printf("cost = %d\n", cost);
	// printf("\n");
	// int	len_a;
	// len_a = lst_len(a_target);
	// printf("node_b is = %d\n", node_b->value);
	// printf("a_target is = %d\n", a_target->value);
	// printf("node_b->index = %d\n", node_b->index);
	// printf("a_target->index = %d\n", a_target->index);
	// printf("nobe_b->center = %d\n", node_b->center);
	TODO gerer si le cost est au dessus du centre et si oui le cost c'est son index
			if (node_b->center)
				rr;
			else
				rrr;
*/

void	sniper(t_list *node_b, t_list *a)
{
	t_list	*first;

	first = node_b;
	while (node_b)
	{
		printf("sniper\n");
		find_target(node_b, a);
		get_cost(node_b->target, node_b);
		node_b = node_b->next;
		if (node_b == first)
			break ;
	}
}

int	is_sorted(t_list *a)
{
	t_list	*tmp;
	t_list	*first;

	first = a;
	tmp = a->next;
	while (a)
	{
		if (a > tmp)
			return (0);
		tmp = tmp->next;
		a = a->next;
		if (tmp == first)
			break ;
	}
	return (1);
}

t_list	*get_cheapest(t_list *b)
{
	t_list	*cheapest;
	t_list	*first;

	first = b;
	if (!b)
		return (NULL);
	cheapest = b;
	while (b)
	{
		if (b == first)
			break ;
		if (b->cost < cheapest->cost)
			cheapest = b;
		b = b->next;
		printf("get_cheapest\n");
	}
	return (cheapest);
}

/*
	TODO tu trouves le nombre le moins cher a deplacer et tu effectues les deplacements

*/