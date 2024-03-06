/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:15:16 by rabouzia          #+#    #+#             */
/*   Updated: 2024/03/06 18:37:19 by rabouzia         ###   ########.fr       */
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

void				rotate_reverse(t_list **a);
void				rotate(t_list **a);
void				swap(t_list *head);
void				push(t_list **t1, t_list **t2);

//----- bonus -----
void				b_ra(t_list **a);
void				b_rb(t_list **b);
void				b_rr(t_list **a, t_list **b);

void				b_sa(t_list *a);
void				b_sb(t_list *b);
void				b_ss(t_list *a, t_list *b);

void				b_rra(t_list **a);
void				b_rrb(t_list **b);
void				b_rrr(t_list **a, t_list **b);

void				b_pa(t_list **a, t_list **b);
void				b_pb(t_list **a, t_list **b);
//----------------- parsing ----------------

long				ft_strlen(const char *str);
long				ft_atol(const char *str);
int					ft_strcmp(char *s1, char *s2);

void				ft_putstr_fd(char *str, int fd);
void				push_init(t_list **a, t_list **b);
void				init_init(t_list *a);
void				remplissage(t_list **head, char **av);

char				**ft_split(char const *s, char c);
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
void				get_cost(t_list *a_target, t_list *node_b, int cost);
void				easy_sort(t_list **a);
t_list				*get_cheapest(t_list *b);

int					is_sorted(t_list *a);
void				instruction(t_list **a, t_list **b);
void				sniper(t_list *node_b, t_list *a);
void				refresh(t_list **a, t_list **b);
void				turkish(t_list **a, t_list **b, char **av);

void				mr_propre(t_list **head);
//------------------- testings ----------------
void				print_lista(t_list *head);
void				print_listb(t_list *head);

//----------------- bonusing -------------------

int					ft_strcmp(char *s1, char *s2);
void				erroring(char *str, t_list **a, t_list **b);
void				hey_listen(char *str, t_list **a, t_list **b);
void				prompt_checker(t_list **a, t_list **b);
int					b_check_input(char **tab, int ac);
int					check_value(char **tab);

#endif