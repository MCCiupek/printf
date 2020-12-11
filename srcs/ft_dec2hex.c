/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec2hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 09:58:22 by mciupek           #+#    #+#             */
/*   Updated: 2020/11/27 16:06:11 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_dec2hex(unsigned long long nb, char *base)
{
	int	r;

	r = nb % 16;
	if (nb / 16)
		ft_dec2hex(nb / 16, base);
	ft_putchar_fd(base[r], 1);
}
