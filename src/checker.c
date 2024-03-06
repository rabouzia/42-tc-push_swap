/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:41:12 by ramzerk           #+#    #+#             */
/*   Updated: 2024/03/06 18:03:35 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"



void	erroring(char *str, t_list **a, t_list **b)
{
	free(str);
	mr_propre(a);
	mr_propre(b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	hey_listen(char *str, t_list **a, t_list **b)
{
	if (!ft_strcmp(str, "pa\n"))
		b_pa(a, b);
	else if (!ft_strcmp(str, "pb\n"))
		b_pb(a, b);
	else if (!ft_strcmp(str, "sa\n"))
		b_sa(*a);
	else if (!ft_strcmp(str, "sb\n"))
		b_sb(*b);
	else if (!ft_strcmp(str, "ss\n"))
		b_ss(*a, *b);
	else if (!ft_strcmp(str, "ra\n"))
		b_ra(a);
	else if (!ft_strcmp(str, "rb\n"))
		b_rb(b);
	else if (!ft_strcmp(str, "rr\n"))
		b_rr(a, b);
	else if (!ft_strcmp(str, "rra\n"))
		b_rra(a);
	else if (!ft_strcmp(str, "rrb\n"))
		b_rrb(b);
	else if (!ft_strcmp(str, "rrr\n"))
		b_rrr(a, b);
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

int	ok_desu(t_list *a, t_list *b)
{
	if (is_sorted(a) && !b)
	{
		write(1, "OK\n", 3);
		return (1);
	}
	else
	{
		write(1, "KO\n", 3);
		return (0);
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	// check_input(av + 1, ac);
	remplissage(&a, av + 1);
	prompt_checker(&a, &b);
	ok_desu(a, b);
	mr_propre(&a);
	if (lst_len(b) != 0)
		mr_propre(&b);
}
