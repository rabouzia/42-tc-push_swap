/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:50:42 by ramzerk           #+#    #+#             */
/*   Updated: 2024/03/03 01:12:04 by ramzerk          ###   ########.fr       */
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
			if (ft_atol(tab[i]) == ft_atol(tab[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_value(char **tab)
{
	long	nbr;
	int		i;

	i = 0;
	while (tab[i])
	{
		nbr = ft_atol(tab[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	check_input(char **tab, int ac)
{
	if (ac < 2)
		return (ft_putstr_fd("Error\nToo few arguments\n", 2), 1);
	if (!check_same(tab))
		return (ft_putstr_fd("Error\nSame arguments\n", 2), 1);
	if (!check_valid(tab))
		return (ft_putstr_fd("Error\nUnvalid arguments\n", 2), 1);
	if (!check_value(tab))
		return (ft_putstr_fd("Error\nUnvalid value\n", 2), 1);
	return (0);
}
