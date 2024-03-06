/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:16:16 by rabouzia          #+#    #+#             */
/*   Updated: 2024/03/06 11:51:07 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (check_input(av + 1, ac))
		return (1);
	turkish(&a, &b, av);
	mr_propre(&a);
	return (0);
}

// void	print_lista(t_list *head)
// {
// 	t_list	*current;

// 	current = head;
// 	printf("Head a:\n");
// 	while (current)
// 	{
// 		printf("node_value = %d  \n ", current->value);
// 		printf("node_index = %d\n", current->index);
// 		printf("prev_value = %d\n", current->prev->value);
// 		// printf("cost = %d\n", current->cost);
// 		// printf("target is = %d\n", current->target->value);
// 		printf("\n");
// 		current = current->next;
// 		if (current == head)
// 			break ;
// 	}
// }
// void	print_listb(t_list *head)
// {
// 	t_list	*current;

// 	current = head;
// 	printf("\n");
// 	printf("Head b:\n");
// 	while (current)
// 	{
// 		printf("node_value = %d  \n ", current->value);
// 		printf("node_index = %d\n", current->index);
// 		printf("prev_value = %d\n", current->prev->value);
// 		if (current->target)
// 			printf("target is = %d\n", current->target->value);
// 		printf("\n");
// 		current = current->next;
// 		if (current == head)
// 			break ;
// 	}
// }