/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:16:16 by rabouzia          #+#    #+#             */
/*   Updated: 2024/02/28 22:40:22 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lista(t_list *head)
{
	t_list	*current;

	current = head;
	printf("Head a:\n");
	while (current)
	{
		printf("node_value = %d  \n ", current->value);
		printf("node_index = %d\n", current->index);
		// printf("cost = %d\n", current->cost);
		// printf("target is = %d\n", current->target->value);
		printf("\n");
		current = current->next;
		if (current == head)
			break ;
	}
}
void	print_listb(t_list *head)
{
	t_list	*current;

	current = head;
	printf("\n");
	printf("Head b:\n");
	while (current)
	{
		printf("node_value = %d  \n ", current->value);
		printf("node_index = %d\n", current->index);
		printf("target is = %d\n", current->target->value);
		printf("cost = %d\n", current->cost);
		printf("\n");
		current = current->next;
		if (current == head)
			break ;
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (ft_putstr_fd("Error\nToo few arguments\n", 2), 1);
	if (!check_argument(av + 1))
		return (ft_putstr_fd("Error\nArguments error\n", 2), 1);
	// if (lst_len(a) <= 3)
	// 	easy_sort(a);
	turkish(&a, &b, av);
	mr_propre(&a);
	return (0);
}

/*
	TODO proteger le atos des valeurs trop grande
*/
