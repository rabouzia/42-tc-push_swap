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
	while (lst_len(*a) > 3)
	{
		pa(a, b);
	}
}

void	instruction_b(t_list **a, t_list **b)
{
	t_list	*c;
	t_list	*target;

	//printf("b value %p\n", *b);
	target = (*b)->target;
	c = get_cheapest(*b);
	//printf("c value %p\n", c);
	// printf("c index %d\n", c->index);
	// printf("c center %d\n", c->center);
	// printf("c cost %d\n", c->cost);
	// printf("target cost c %d\n", target->index);
	// printf("target %d\n", target->center);
	while (c->index != 0 && c->center == 1)
	{
		rb(b);
		//c->index--;
		init_value(*b);
	}
	while (target->index != 0 && target->center == 1)
	{
		ra(a);
		//target->index--;
		init_value(*a);
	}
	while (c->index != 1 && c->center == 0)
	{
		rrb(b);
		//c->index--;
		init_value(*b);

	}
	while (target->index != 0 && target->center == 0)
	{
		rra(a);
		//target->index--;
		init_value(*a);
	}
	pb(a, b);
}

void	refresh(t_list **a, t_list **b)
{
	t_list *smallest;

	while (*b)
	{
		init_value(*a);
		init_value(*b);
		sniper(*b, *a);
		//print_lista(*a);
		//print_listb(*b);
		//printf("\ncheapest is %p\n", get_cheapest(*b));
		//printf("\n\n\n");
		instruction_b(a, b);
	}
	init_value(*a);
	smallest = find_smallest(*a);
	//printf("SMAL : %d\n", smallest->value);
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
	init_value(*a); /*a enlever a la toute fin du projet - si ca casse tout garde les*/
	init_value(*b);
}

void	turkish(t_list **a, t_list **b, char **av)
{
	remplissage(a, av + 1);
	init_init(*a);
	//print_lista(*a);
	//print_listb(*b);
	push_init(a, b);
	easy_sort(a);
	refresh(a, b);
	//print_lista(*a);
	//print_listb(*b);
}
