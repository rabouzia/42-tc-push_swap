/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:55:26 by rabouzia          #+#    #+#             */
/*   Updated: 2024/01/04 12:43:54 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*prev;

}					t_list;

t_list	*create_list(int a)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = a;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	print_list(t_list *current)
{
	printf("current.value = %d\n", current->value);
	printf("current.next = %p\n", (void *)current->next);
	printf("current.prev = %p\n", (void *)current->prev);
}

int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	c = create_list(1);
	b = create_list(7);
	c = create_list(4);
    
	a->next = b;
	b->next = c;
	c->next = a;
    
	a->prev = c;
	b->prev = a;
	c->prev = b;
	
    printf("a = \n");
	print_list(a);
	printf("b = \n");
	print_list(b);
	printf("c = \n");
	print_list(c);
    free(a); free (b); free(c);
}
