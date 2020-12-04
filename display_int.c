/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcciupek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:58:04 by mcciupek          #+#    #+#             */
/*   Updated: 2020/12/03 17:12:41 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_change_prec(int size, int sign, t_params *params)
{
	if (params->flags != '-' && size + sign > params->n_prec)
		params->n_prec = size + sign;
	else
		params->n_prec += sign;
}

void	ft_write_int(int n, t_params *params)
{
	if (n < 0)
		n = -n;
	if (n == -2147483648)
		ft_writeui(2147483648, 1);
	else if (n || !params->b_prec || params->n_prec)
		ft_putnbr_fd(n, 1);
}

size_t	display_int(int n, t_params *params)
{
	int	size;
	int	sign;
	int	nb_char;

	size = ft_nbrlen(n, 10);
	if (!n && params->b_prec && !params->n_prec)
		size = 0;
	sign = 0;
	if (n < 0)
		sign = 1;
	nb_char = ft_max(params->n_width, params->n_prec + sign, size + sign);
	ft_change_prec(size, sign, params);
	if (!params->flags || (params->flags == '0' && params->b_prec))
		print_char(' ', nb_char - params->n_prec, params);
	if (sign)
		print_char('-', 1, params);
	if (params->flags != '-')
		print_char('0', nb_char - params->count - size, params);
	if (params->flags == '-')
		print_char('0', params->n_prec - size - sign, params);
	ft_write_int(n, params);
	if (params->flags == '-')
		print_char(' ', nb_char - params->count - size, params);
	return (size + params->count);
}
