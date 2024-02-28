/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:26:48 by rabouzia          #+#    #+#             */
/*   Updated: 2024/02/12 23:01:28 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_putnbr_base_unsigned(unsigned long nbr, char *base)
{
	unsigned long	a;
	unsigned long	i;

	i = 0;
	a = ft_strlen(base);
	if (nbr >= a)
	{
		i += ft_putnbr_base_unsigned(nbr / a, base);
		i += ft_putnbr_base_unsigned(nbr % a, base);
	}
	else
	{
		ft_putchar(base[nbr]);
		i++;
	}
	return (i);
}

int	ft_putnbr_base(long nbr, char *base)
{
	if (nbr < 0)
		return (ft_putchar('-') + ft_putnbr_base_unsigned(-nbr, base));
	return (ft_putnbr_base_unsigned(nbr, base));
}
int	print_decimal(int a)
{
	return (ft_putnbr_base(a, "0123456789"));
}

int	check(va_list *args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(*args, int));
	if (c == 's')
		count += ft_putstr(va_arg(*args, char *));
	if (c == 'p')
		count += print_address((unsigned long)va_arg(*args, void *),
				"0123456789abcdef");
	if (c == 'x')
		count += ft_putnbr_base(va_arg(*args, unsigned int),
				"0123456789abcdef");
	if (c == 'X')
		count += ft_putnbr_base(va_arg(*args, unsigned int),
				"0123456789ABCDEF");
	if (c == 'i' || c == 'd')
		count += print_decimal(va_arg(*args, int));
	if (c == '%')
		count += ft_putchar('%');
	if (c == 'u')
		count += ft_putnbr_base((long)va_arg(*args, unsigned int),
				"0123456789");
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		res;

	va_start(list, str);
	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			res += check(&list, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			res++;
		}
		i++;
	}
	va_end(list);
	return (res);
}
