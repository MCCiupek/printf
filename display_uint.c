/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcciupek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:58:04 by mcciupek          #+#    #+#             */
/*   Updated: 2020/12/03 14:42:31 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t		display_uint(unsigned int n, t_params *params)
{
	int	size;
	int	nb_char;

	size = ft_nbrlen(n, 10);
	if (!n && params->b_prec && !params->n_prec)
		size = 0;
	nb_char = ft_max(params->n_width, params->n_prec, size);
	if (params->flags != '-' && size > params->n_prec)
		params->n_prec = size;
	if (!params->flags || (params->flags == '0' && params->b_prec))
		print_char(' ', nb_char - params->n_prec, params);
	if (params->flags != '-')
		print_char('0', nb_char - params->count - size, params);
	if (params->flags == '-')
		print_char('0', params->n_prec - size, params);
	if (n || !params->b_prec || params->n_prec)
		ft_writeui(n, 1);
	if (params->flags == '-')
		print_char(' ', nb_char - params->count - size, params);
	return (size + params->count);
}
