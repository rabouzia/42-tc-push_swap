/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:15:13 by rabouzia          #+#    #+#             */
/*   Updated: 2023/12/28 17:30:55 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct intarray	intarray;

struct					intarray
{
	int					*data;
	int					len;
};

// intarray	receive(int len)
// {
// 	intarray	tab;
// 	intarray	i;

// 	tab.len = len;
// 	tab.data = malloc(len * sizeof(int));
// }
void	tab_filler(intarray tab, int a, int len)
{
	tab.data[len] = a;
}

int	tab_create(void)
{
}
void	swap(int *tab)
{
	int	tmp;

	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
}

void push(int *a, int *b, int tab_len)
{
	if (!a || tab_len <= 0)
		return;
	b[0] = a[0];
	int i;
	i = 0;
	while (i < tab_len) 
	{
		a[i] = a[i + 1];
		i++;
      	}
}
void	rotate(int *a, int tab_len)
{
	int	i;
	int	tmp;

	if (tab_len <= 0 || !a)
		return ;
	i = 1;
	tmp = a[0];
	while (i < tab_len)
	{
		a[i - 1] = a[i];
		i++;
	}
	a[tab_len - 1] = tmp;
}

void	print_tab(int *tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
		printf("%d ", tab[i++]);
	printf("\n");
}

void reverse_rotate(int *a, int tab_len) {
    if (tab_len <= 1) {
        return;
    }

    int tmp = a[tab_len - 1];
    int i = tab_len - 1;

    while (i > 0) {
        a[i] = a[i - 1];
        i--;
    }

    a[0] = tmp;
}

#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int a[6] = {2, 7, -1, 4, 9, 1};
	int b[1];

	int len = 6;
	int i = 0;

	print_tab(a, len);
	print_tab(b, 1);
	push(a,b,6);
	print_tab(a, len);
	print_tab(b, 1);
}
