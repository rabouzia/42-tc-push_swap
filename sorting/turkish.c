/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:39:29 by rabouzia          #+#    #+#             */
/*   Updated: 2024/02/28 15:54:07 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_init(t_list **a, t_list **b)
{
	while (lst_len(*a) != 3)
	{
		pa(a, b);
	}
}

void	instruction_b(t_list **a, t_list **b)
{
	t_list	*c;
	t_list	*target;

	target = *a;
	c = get_cheapest(*b);
	// printf("c value %d\n", c->value);
	// printf("c index %d\n", c->index);
	// printf("c center %d\n", c->center);
	// printf("c cost %d\n", c->cost);
	// printf("target cost c %d\n", target->index);
	// printf("target %d\n", target->center);
	printf("\n sdf \n");
	while (c->index != 0 && c->center == 1)
	{
		rb(b);
		c->index--;
	}
	while (target->index != 0 && target->center == 1)
	{
		ra(a);
		target->index--;
	}
	while (c->index != 1 && c->center == 0)
	{
		rrb(b);
		c->index--;
	}
	while (target->index != 0 && target->center == 0)
	{
		rra(a);
		target->index--;
	}
	pb(a, b);
}

void	refresh(t_list **a, t_list **b)
{
	int	i;

	i = 15;
	init_value(*a);
	init_value(*b);
	while (i)
	{
		sniper(*b, *a);
		instruction_b(a, b);
		printf("\ncheapest is %d\n", get_cheapest(*b)->value);
		printf("\n\n\n\n\n");
		i--;
	}
}

void	turkish(t_list **a, t_list **b, char **av)
{
	remplissage(a, av + 1);
	print_lista(*a);
	print_listb(*b);
	push_init(a, b);
	easy_sort(a);
	refresh(a, b);
	print_lista(*a);
	print_listb(*b);
}
