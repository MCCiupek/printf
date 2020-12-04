/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:57:45 by mciupek           #+#    #+#             */
/*   Updated: 2020/12/03 17:44:00 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		init_params(t_params *params)
{
	params->flags = 0;
	params->n_width = 0;
	params->n_prec = 0;
	params->b_prec = 0;
	params->count = 0;
}

static size_t	ft_cast(char c, t_params *params, va_list args)
{
	size_t	i;

	i = 0;
	if (c == 'c')
		i += display_char(va_arg(args, int), params);
	else if (c == 's')
		i += display_str((const char *)va_arg(args, char *), params);
	else if (c == 'p')
		i += display_ptr((void *)va_arg(args, void *), params);
	else if (c == 'd' || c == 'i')
		i += display_int((int)va_arg(args, int), params);
	else if (c == 'u')
		i += display_uint((unsigned int)va_arg(args, int), params);
	else if (c == 'x')
		i += display_hex((unsigned int)va_arg(args, int), params);
	else if (c == 'X')
		i += display_hex_maj((unsigned int)va_arg(args, int), params);
	else if (c == '%')
		i += display_char('%', params);
	return (i);
}

int			ft_printf(const char *format, ...)
{
	size_t			i;
	char				c;
	va_list			args;
	t_params	params;

	i = 0;
	va_start(args, format);
	while ((c = *format++))
	{
		init_params(&params);
		if (c != '%')
		{
			ft_putchar_fd(c, 1);
			i++;
			continue ;
		}
		format = ft_params(format, &params, args);
		i += ft_cast(*format++, &params, args);
	}
	va_end(args);
	return (i);
}
