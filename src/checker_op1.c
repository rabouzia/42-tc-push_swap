/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:00:04 by ramzerk           #+#    #+#             */
/*   Updated: 2024/03/06 18:07:34 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	b_pa(t_list **a, t_list **b)
{
	push(a, b);
}

void	b_pb(t_list **a, t_list **b)
{
	push(b, a);
}

void	b_rra(t_list **a)
{
	rotate_reverse(a);
}

void	b_rrb(t_list **b)
{
	rotate_reverse(b);
}

void	b_rrr(t_list **a, t_list **b)
{
	rotate_reverse(b);
	rotate_reverse(a);
}
