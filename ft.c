/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcciupek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:27:14 by mcciupek          #+#    #+#             */
/*   Updated: 2020/12/03 17:41:45 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_nbrlen(long long nb, int base)
{
	size_t	size;

	size = 1;
	while (nb / base)
	{
		size++;
		nb = nb / base;
	}
	return (size);
}

size_t	ft_nbrlen_long(unsigned long long nb, int base)
{
	size_t	size;

	size = 1;
	while ((nb = nb / base))
		size++;
	return (size);
}

void	print_char(int c, int wid, t_params *params)
{
	while (wid-- > 0)
	{
		ft_putchar_fd(c, 1);
		params->count++;
	}
}

void	ft_writeui(unsigned int nb, int fd)
{
	int	r;

	r = nb % 10;
	if (nb / 10)
		ft_writeui(nb / 10, fd);
	r = r + '0';
	ft_putchar_fd(r, fd);
}

int		ft_max(int a, int b, int c)
{
	int	res;

	if (a >= b)
		res = a;
	else
		res = b;
	if (c >= res)
		res = c;
	return (res);
}
