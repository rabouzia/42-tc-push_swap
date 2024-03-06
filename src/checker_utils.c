/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:01:58 by ramzerk           #+#    #+#             */
/*   Updated: 2024/03/06 18:48:29 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_ss(t_list *a, t_list *b)
{
	swap(a);
	swap(b);
}

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && (*s1 && *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	b_check_input(char **tab, int ac)
{
	(void)ac;
	if (!check_same(tab))
		return (ft_putstr_fd("Error\n", 2), 0);
	if (!check_valid(tab))
		return (ft_putstr_fd("Error\n", 2), 0);
	if (!check_value(tab))
		return (ft_putstr_fd("Error\n", 2), 0);
	return (1);
}