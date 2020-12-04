/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcciupek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:08:13 by mcciupek          #+#    #+#             */
/*   Updated: 2020/12/04 17:26:48 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_params
{
	unsigned char	flags;
	int			n_width;
	int			n_prec;
	unsigned int	b_prec;
	unsigned int	count;
}			t_params;

int	ft_printf(const char *format, ...);
void	ft_dec2hex(unsigned long long n, char *base);
size_t	ft_nbrlen(long long nb, int base);
size_t	ft_nbrlen_long(unsigned long long nb, int base);
size_t	ft_flags(const char *flag, va_list args);
int	ft_max(int a, int b, int c);
void	ft_writeui(unsigned int nb, int fd);
void	print_char(int c, int wid, t_params *params);
const char	*ft_params(const char *format, t_params *params, va_list args);
size_t	display_char(int c, t_params *params);
size_t	display_str(const char *str, t_params *params);
size_t	display_int(int n, t_params *params);
size_t	display_uint(unsigned int n, t_params *params);
size_t	display_hex(unsigned int n, t_params *params);
size_t	display_hex_maj(unsigned int n, t_params *params);
size_t	display_ptr(void *adrs, t_params *params);

#endif
