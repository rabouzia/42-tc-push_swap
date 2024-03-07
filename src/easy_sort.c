/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:32:04 by ramzerk           #+#    #+#             */
/*   Updated: 2024/03/06 20:33:52 by rabouzia         ###   ########.fr       */
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

	if (!a)
		return (NULL);
	first = a;
	smallest = a;
	while (a)
	{
		if (a->value < smallest->value)
			smallest = a;
		a = a->next;
		if (a == first)
			break ;
	}
	return (smallest);
}

int	is_sorted(t_list *a)
{
	t_list	*tmp;
	t_list	*first;

	first = a;
	tmp = a->next;
	while (a)
	{
		if (a->value > tmp->value)
			return (0);
		tmp = tmp->next;
		a = a->next;
		if (tmp == first)
			break ;
	}
	return (1);
}

void	easy_sort(t_list **a)
{
	t_list	*biggest;

	if (lst_len(*a) == 1)
		return ;
	biggest = find_biggest(*a);
	if (*a == biggest)
		ra(a);
	else if ((*a)->next == biggest)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(*a);
}
