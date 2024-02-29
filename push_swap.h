/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:15:16 by rabouzia          #+#    #+#             */
/*   Updated: 2024/02/27 12:06:48 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
void init_init(t_list *a);

// pushing

t_list				*create_node(int a);
void				delete_node_head(t_list **head);
void				push(t_list **t1, t_list **t2);
void				pa(t_list **b, t_list **a);
void				pb(t_list **a, t_list **b);

// swaping

void				swap(t_list *head);
void				sa(t_list *a);
void				sb(t_list *b);
void				ss(t_list *a, t_list *b);

// rotating

void				rotate(t_list **a);
void				ra(t_list **a);
void				rb(t_list **b);
void				rr(t_list **a, t_list **b);

// reverse rotating

void				rotate_reverse(t_list **a);
void				rra(t_list **a);
void				rrb(t_list **b);
void				rrr(t_list **a, t_list **b);

// tools for creating a chained list

void				ft_lstadd_back(t_list **head, t_list *new);
t_list				*create_first(t_list *head, int n);
t_list				*add_next(t_list **head, int n);
void				remplissage(t_list **head, char **av);

// ft_printf

int					ft_printf(const char *str, ...);
int					check(va_list *args, char c);
int					ft_putstr(const char *str);
int					ft_putchar(const char c);
int					print_address(unsigned long a, char *s);
long				ft_putnbr_base_unsigned(unsigned long nbr, char *base);
int					ft_putnbr_base(long nbr, char *base);
int					print_decimal(int a);

// tools to split, print and join integers

size_t				ft_countword(char const *s, char c);
char				**ft_split(char const *s, char c);
char				*empty(void);
char				*ft_substr(const char *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t len);
size_t				ft_atos(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*str_loopjoin(char **str);
char				*ft_strdup(const char *src);
// void				print_list(t_list *head);
void				print_lista(t_list *head);
void				print_listb(t_list *head);

void				push_init(t_list **a, t_list **b);

// useful crazy tools

void				ft_putstr_fd(char *str, int fd);
int					lst_len(t_list *head);
void				turkish(t_list **a, t_list **b, char **av);
char				*ft_strchr(const char *str, int c);
t_list				*find_biggest(t_list *a);
t_list				*find_smallest(t_list *a);
void				find_target(t_list *node_b, t_list *a);
void				init_value(t_list *a);
void				get_cost(t_list *a_target, t_list *node_b);
void				easy_sort(t_list **a);
void				mr_propre(t_list **head);
void				ft_lstdelone(t_list *lst);
void				sniper(t_list *node_b, t_list *a);
void				instruction(t_list **a, t_list **b);
void				refresh(t_list **a, t_list **b);

// checking functions

int					is_valid(char *str);
int					check_valid(char **tab);
int					check_same(char **tab);
int					check_argument(char **tab);
int					ft_strcmp(char *s1, char *s2);
int					is_sorted(t_list *a);
t_list				*get_cheapest(t_list *b);

#endif