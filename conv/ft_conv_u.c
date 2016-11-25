/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:08:57 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/25 19:29:32 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

static int		ft_llu(unsigned long long n, int *c)
{
	if (n >= 10)
	{
		ft_llu(n / 10, c);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
	(*c)++;
	return (1);
}

static int		ft_cu(unsigned char n, int *c)
{
	if (n >= 10)
	{
		ft_cu(n / 10, c);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
	(*c)++;
	return (1);
}

static int		ft_su(unsigned short n, int *c)
{
	if (n >= 10)
	{
		ft_su(n / 10, c);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
	(*c)++;
	return (1);
}

int				ft_u(va_list ap, unsigned long f, int *c)
{
	if (f >> 5 & 1)
		return (ft_cu(va_arg(ap, signed char), c));
	if (f >> 6 & 1)
		return (ft_su(va_arg(ap, short), c));
	if (f >> 7 & 1)
		return (ft_llu(va_arg(ap, unsigned long long), c));
	if (f >> 8 & 1)
		return (ft_llu(va_arg(ap, unsigned long), c));
	if (f >> 9 & 1)
		return (ft_llu(va_arg(ap, uintmax_t), c));
	if (f >> 10 & 1)
		return (ft_llu(va_arg(ap, size_t), c));
	return (ft_llu(va_arg(ap, unsigned int), c));
}
