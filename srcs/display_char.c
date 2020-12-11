/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcciupek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:58:04 by mcciupek          #+#    #+#             */
/*   Updated: 2020/12/01 16:37:02 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	display_char(int c, t_params *params)
{
	if (params->flags == '-')
	{
		ft_putchar_fd((unsigned char)c, 1);
		print_char(' ', params->n_width - 1, params);
	}
	else if (params->flags == '0')
	{
		print_char('0', params->n_width - 1, params);
		ft_putchar_fd((unsigned char)c, 1);
	}
	else
	{
		print_char(' ', params->n_width - 1, params);
		ft_putchar_fd((unsigned char)c, 1);
	}
	return (params->count + 1);
}
