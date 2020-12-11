/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcciupek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:08:57 by mcciupek          #+#    #+#             */
/*   Updated: 2020/12/04 18:15:00 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	display_ptr(void *adrs, t_params *params)
{
	unsigned long long	value;
	int					size;
	int					nb_char;

	value = (unsigned long long)adrs;
	size = ft_nbrlen_long(value, 16) + 2;
	if (!adrs && params->b_prec && !params->n_prec)
		size = 2;
	params->n_prec += 2;
	nb_char = ft_max(params->n_width, params->n_prec, size);
	if (params->flags != '-' && size > params->n_prec)
		params->n_prec = size;
	if (!params->flags || (params->flags == '0' && params->b_prec))
		print_char(' ', nb_char - params->n_prec, params);
	ft_putstr_fd("0x", 1);
	if (params->flags != '-')
		print_char('0', nb_char - params->count - size, params);
	if (params->flags == '-')
		print_char('0', params->n_prec - size, params);
	if (adrs || !params->b_prec || params->n_prec - 2)
		ft_dec2hex(value, "0123456789abcdef");
	if (params->flags == '-')
		print_char(' ', nb_char - params->count - size, params);
	return (size + params->count);
}
