/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mon_pote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:50:42 by ramzerk           #+#    #+#             */
/*   Updated: 2024/02/16 18:05:03 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
		i++;
	else if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (str[i] == '\0' && i != 0);
}

int	check_valid(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!is_valid(tab[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_same(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_atos(tab[i]) == ft_atos(tab[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_argument(char **tab)
{
	if (!check_same(tab) || !check_valid(tab))
		return (0);
	return (1);
}
	// while (tab[i])
	// {
	// 	if (check_same(tab, tab[i], i));
	// 		return 4
	// 	check_valid(tab[i]);
	// 	i++;
	// }