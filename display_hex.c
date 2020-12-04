/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:16:26 by mciupek           #+#    #+#             */
/*   Updated: 2020/12/03 14:40:40 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	display_hex(unsigned int n, t_params *params)
{
	int	size;
	int	nb_char;

	size = ft_nbrlen(n, 16);
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
		ft_dec2hex(n, "0123456789abcdef");
	if (params->flags == '-')
		print_char(' ', nb_char - params->count - size, params);
	return (size + params->count);
}
