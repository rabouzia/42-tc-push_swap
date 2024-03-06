/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:35:28 by rabouzia          #+#    #+#             */
/*   Updated: 2024/03/06 19:08:09 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_reverse(t_list **a)
{
	if (!a || !(*a) || lst_len(*a) == 1)
		return ;
	*a = (*a)->prev;
}

void	rra(t_list **a)
{
	rotate_reverse(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	rotate_reverse(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	rotate_reverse(b);
	rotate_reverse(a);
	write(1, "rrr\n", 4);
}
