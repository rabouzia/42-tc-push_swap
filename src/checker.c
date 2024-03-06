/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:41:12 by ramzerk           #+#    #+#             */
/*   Updated: 2024/03/06 11:52:07 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 & *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	erroring(char *str, t_list **a, t_list **b)
{
	free(str);
	mr_propre(a);
	mr_propre(b);
	ft_putstr_fd("Error\nInvalid value\n", 2);
	exit(1);
}

void	hey_listen(char *str, t_list **a, t_list **b)
{
	if (ft_strcmp(str, "pa/n"))
		pa(a, b);
	if (ft_strcmp(str, "pb/n"))
		pb(a, b);
	if (ft_strcmp(str, "sa/n"))
		sa(*a);
	if (ft_strcmp(str, "sb/n"))
		sb(*b);
	if (ft_strcmp(str, "ss/n"))
		ss(*a, *b);
	if (ft_strcmp(str, "ra/n"))
		ra(a);
	if (ft_strcmp(str, "rb/n"))
		rb(b);
	if (ft_strcmp(str, "rr/n"))
		rr(a, b);
	if (ft_strcmp(str, "rra/n"))
		rra(a);
	if (ft_strcmp(str, "rrb/n"))
		rrb(b);
	if (ft_strcmp(str, "rrr/n"))
		rrr(a, b);
	else
		erroring(str, a, b);
}

void	prompt_checker(t_list **a, t_list **b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		hey_listen(str, a, b);
		free(str);
		str = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (check_input(av + 1, ac))
		return (1);
	remplissage(&a, av + 1);
	prompt_checker(&a, &b);
}
