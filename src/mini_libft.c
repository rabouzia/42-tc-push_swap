/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:48:24 by ramzerk           #+#    #+#             */
/*   Updated: 2024/03/03 01:06:59 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int	lst_len(t_list *head)
{
	int		i;
	t_list *first;
	
	i = 0;
	first = head;
	while (head)
	{
		i++;
		head = head->next;
		if (head == first)
			break;
	}
	return (i);
}

long	ft_strlen(const char *str)
{
	long	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

long	ft_atol(const char *str)
{
	long i;
	long p;
	long n;

	i = 0;
	p = 1;
	n = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			p *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (n * p);
}
