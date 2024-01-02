/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:26:56 by rabouzia          #+#    #+#             */
/*   Updated: 2024/01/02 15:23:23 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;

}					t_node;

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}

void	swap(t_node *tab)
{
	int	tmp;

	tmp = tab->content;
	tab->content = tab->next->content;
	tab->next->content = tmp;
}
void	push(t_node **t1, t_node **t2)
{
	int	tmp;

	tmp = pop(t1);
	append(t2, tmp);
}

void	rotate(t_node *t1)
{
	t_node	*tmp;

	tmp = t1;
	t1 = t1->next;
	ft_lstadd_back(t1, tmp);
}

int	pop(t_node **stack)
{
	int		ret;
	t_node	*current;

	current = *stack;
	ret = current->content;
	*stack = current->next;
	free(current);
	return (ret);
}

void delete (t_node **trash)
{
}

void	append(t_node **stack, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->content = value;
	new->next = *stack;
	*stack = new;
}

/*
fonction pop qui peut supprimer le premier noeaud de ta liste ;
et retourner la valeur du noeud en question

puis faire une fonction append qui a partiir d une valeur cree un noeud en debut de chaine pour poiuvoir les creers au debuut et aussi pouvoir les append en milieu
d execution
*/