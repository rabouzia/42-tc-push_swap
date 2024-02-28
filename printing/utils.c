/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:27:36 by rabouzia          #+#    #+#             */
/*   Updated: 2024/02/04 18:47:07 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putchar(const char c)
{
	return (write(1, &c, 1));
}


int	print_address(unsigned long a, char *s)
{
	if (a == 0)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_putnbr_base_unsigned(a, s));
}