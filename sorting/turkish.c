/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:39:29 by rabouzia          #+#    #+#             */
/*   Updated: 2024/03/03 01:20:39 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_init(t_list **a, t_list **b)
{
	while (lst_len(*a) > 3)
	{
		pa(a, b);
	}
}

void	instruction_b(t_list **a, t_list **b)
{
	t_list	*c;
	t_list	*target;

	c = get_cheapest(*b);
	target = c->target;
	while ((c->index != 0 && c->center == 1) && (target->index != 0 && target->center == 1) )
	{
		rr(a,b);
		init_value(*b);
		init_value(*a);
	}
	while ((c->index != 0 && c->center == 0) && (target->index != 0 && target->center == 0))
	{
		rrr(a,b);
		init_value(*a);
		init_value(*b);
	}
	while (c->index != 0 && c->center == 1)
	{
		rb(b);
		init_value(*b);
	}
	while (target->index != 0 && target->center == 1)
	{
		ra(a);
		init_value(*a);
	}
	while (c->index != 0 && c->center == 0)
	{
		rrb(b);
		init_value(*b);
	}
	while (target->index != 0 && target->center == 0)
	{
		rra(a);
		init_value(*a);
	}
	pb(a, b);
}

void	refresh(t_list **a, t_list **b)
{
	t_list	*smallest;

	while (*b)
	{
		init_value(*a);
		init_value(*b);
		sniper(*b, *a);
		instruction_b(a, b);
	}
	init_value(*a);
	smallest = find_smallest(*a);
	while (smallest->index != 0 && smallest->center == 1)
	{
		ra(a);
		init_value(*a);
	}
	while (smallest->index != 0 && smallest->center == 0)
	{
		rra(a);
		init_value(*a);
	}
	init_value(*a);
	init_value(*b);
}

void	turkish(t_list **a, t_list **b, char **av)
{
	remplissage(a, av + 1);
	init_init(*a);
	push_init(a, b);
	easy_sort(a);
	refresh(a, b);
}
