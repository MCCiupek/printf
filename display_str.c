/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcciupek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:58:04 by mcciupek          #+#    #+#             */
/*   Updated: 2020/12/04 12:44:59 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_new_str(const char *str, t_params *params)
{
	char	*s;

	if (!str)
		str = "(null)";
	if (params->b_prec)
		s = ft_substr(str, 0, params->n_prec);
	else
		s = (char *)str;
	return (s);
}

size_t	display_str(const char *str, t_params *params)
{
	int		size;
	char	*s;

	s = ft_new_str(str, params);
	size = ft_strlen(s);
	if (params->flags == '-')
	{
		ft_putstr_fd(s, 1);
		print_char(' ', params->n_width - size, params);
	}
	else
	{
		if (params->flags == '0')
			print_char('0', params->n_width - size, params);
		else
			print_char(' ', params->n_width - size, params);
		ft_putstr_fd(s, 1);
	}
	return (size + params->count);
}
