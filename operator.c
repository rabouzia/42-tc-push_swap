/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <rabouzia@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:26:56 by rabouzia          #+#    #+#             */
/*   Updated: 2024/01/01 15:01:13 by ramzerk          ###   ########.fr       */
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

t_node	*ft_lstnew(void *content)
{
	t_node	*res;

	res = malloc(sizeof(t_node));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}
t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

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
void	push(t_node *t1, t_node *t2)
{
	t_node	*tmp;

	tmp = t1->content;
	t2->content = tmp;
	delete (t1->content);
}

void	rotate(t_node *t1)
{
	t_node	*tmp;

	tmp = t1;
	t1 = t1->next;
	ft_lstadd_back(t1, tmp);
}
