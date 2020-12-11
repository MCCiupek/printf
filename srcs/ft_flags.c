/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:44:36 by mciupek           #+#    #+#             */
/*   Updated: 2020/12/04 12:36:45 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		set_width(t_params *params, int n)
{
	if (params->b_prec == 1)
		params->n_prec = n;
	else
		params->n_width = n;
}

const char	*ft_star(const char *format, t_params *params, va_list args)
{
	int	n;

	if ((n = va_arg(args, int)) < 0 && !params->b_prec)
	{
		n = -n;
		params->flags = '-';
	}
	set_width(params, n);
	format++;
	return (format);
}

const char	*ft_digit(const char *format, t_params *params)
{
	int	n;

	n = 0;
	while (ft_isdigit(*format))
	{
		n = n * 10 + *format - '0';
		format++;
	}
	set_width(params, n);
	return (format);
}

const char	*ft_params(const char *format, t_params *params, va_list args)
{
	while (*format)
	{
		if (*format == '-')
			params->flags = '-';
		else if (*format == '0' && params->flags != '-' && !params->b_prec)
			params->flags = '0';
		else if (*format == '.')
			params->b_prec = 1;
		else if (*format == '*')
		{
			format = ft_star(format, params, args);
			continue ;
		}
		else if (ft_isdigit(*format))
		{
			format = ft_digit(format, params);
			continue ;
		}
		else
			break ;
		format++;
	}
	if (params->n_prec < 0)
		params->b_prec = 0;
	return (format);
}
