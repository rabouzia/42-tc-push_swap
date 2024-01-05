/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:55:26 by rabouzia          #+#    #+#             */
/*   Updated: 2024/01/05 15:48:01 by rabouzia         ###   ########.fr       */
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

t_list	*create_node(int a)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = a;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	print_AD_list(t_list *current)
{
	printf("current = %p\n", current);
	printf("current.value = %d\n", current->value);
	printf("current.next = %p\n", current->next);
	printf("current.prev = %p\n", current->prev);
}

void	print_list(t_list *start)
{
	t_list	*current;

	current = start;
	while (current)
	{
		printf("Node value: %d\n", current->value);
		current = current->next;
	}
}

int	pop(t_list *stack)
{
	int		ret;
	t_list	*current;

	if (!stack)
		return (0);
	current = stack;
	ret = current->value;
	if (current->next)
	{
		stack = current->next;
		stack->prev = NULL;
		free(current);
	}
	else
	{
		free(stack);
		stack = NULL;
	}
	return (ret);
}

// void	append(t_list *stack, int value)
// {
// 	t_list	*new;

// 	if (!stack)
// 	{
// 		stack = create_node(value);
// 		return ;
// 	}
// 	new = create_node(value);
// 	if (!new)
// 		return ;
// 	new->next = stack;
// 	new->prev = NULL;
// 	stack->prev = new;
// 	stack = new;
// }

t_list *append(t_list *stack, int value)
{
    t_list *new = create_node(value);

    if (!new)
    {
        // Handle memory allocation failure
        return stack;
    }

    if (!stack)
    {
        // If the list is empty, the new node is both the head and tail
        return new;
    }

    // Update pointers to insert the new node at the beginning
    new->next = stack;
    stack->prev = new;

    return new;
}

void	push(t_list *t1, t_list *t2)
{
	int	tmp;

	if (!t1)
		return ;
	tmp = pop(t1);
	append(t2, tmp);
}

int	main(void)
{
	t_list	*a;
	t_list	*d;

	d = NULL;
	a = NULL;
	a = create_node(1);
	a = append(a, 7);
	a = append(a, 4);
	printf("a1 = ");
	print_list(a);
	push(a, d);
	printf("push ... \n");
	printf("a2 = ");
	print_list(a);
	printf("d = ");
	print_list(d);
	free(a);
}
