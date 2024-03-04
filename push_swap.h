/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:15:16 by rabouzia          #+#    #+#             */
/*   Updated: 2024/03/04 03:04:31 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				cost;
	int				center;
	int				index;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

//----------------- operators ----------------
void				pa(t_list **b, t_list **a);
void				pb(t_list **a, t_list **b);

void				sa(t_list *a);
void				sb(t_list *b);
void				ss(t_list *a, t_list *b);

void				ra(t_list **a);
void				rb(t_list **b);
void				rr(t_list **a, t_list **b);

void				rra(t_list **a);
void				rrb(t_list **b);
void				rrr(t_list **a, t_list **b);

//----------------- parsing ----------------

long				ft_strlen(const char *str);
long				ft_atol(const char *str);

void				ft_putstr_fd(char *str, int fd);
void				push_init(t_list **a, t_list **b);
void				init_init(t_list *a);
void				remplissage(t_list **head, char **av);

int					is_valid(char *str);
int					check_valid(char **tab);
int					check_same(char **tab);
int					check_argument(char **tab);
int					check_input(char **tab, int ac);

//----------------- sorting ----------------

int					lst_len(t_list *head);
t_list				*find_biggest(t_list *a);
t_list				*find_smallest(t_list *a);
void				find_target(t_list *node_b, t_list *a);
void				init_value(t_list *a);
void				get_cost(t_list *a_target, t_list *node_b);
void				easy_sort(t_list **a);
t_list				*get_cheapest(t_list *b);

int					is_sorted(t_list *a);
void				instruction(t_list **a, t_list **b);
void				sniper(t_list *node_b, t_list *a);
void				refresh(t_list **a, t_list **b);
void				turkish(t_list **a, t_list **b, char **av);

void				mr_propre(t_list **head);

void				print_lista(t_list *head);
void				print_listb(t_list *head);

#endif