/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:39:35 by rabouzia          #+#    #+#             */
/*   Updated: 2024/02/13 15:19:26 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *head)
{
	int		tmp;
	t_list	*second;

	second = head->next;
	tmp = head->value;
	head->value = second->value;
	second->value = tmp;
}

void	sa(t_list *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_list *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list *a, t_list *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
