/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:54:43 by rabouzia          #+#    #+#             */
/*   Updated: 2024/03/03 01:12:43 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int a)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = a;
	new->next = new;
	new->prev = new;
	return (new);
}

void	ft_lstadd_back(t_list **a, t_list *new)
{
	t_list	*last;
	t_list	*first;

	if (!new)
		return ;
	if (*a)
	{
		first = *a;
		last = first->prev;
		new->next = first;
		new->prev = last;
		first->prev = new;
		last->next = new;
	}
	else
	{
		*a = new;
		new->next = new;
		new->prev = new;
	}
}

t_list	*add_next(t_list **head, int n)
{
	t_list	*new;

	new = create_node(n);
	ft_lstadd_back(head, new);
	return (new);
}

void init_init(t_list *a)
{
	t_list *tmp = a;
	while (a)
	{
		a->cost = 0;
		a->index = 0;
		a->center = 0;
		a->target = 0;
		a = a->next;
		if (a == tmp)
			break;
	}
}

void	remplissage(t_list **head, char **av)
{
	if (!av || !*av)
		return ;
	while (*av)
	{
		add_next(head, ft_atol(*av));
		av++;
	}
}
