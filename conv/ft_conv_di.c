/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:13:29 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/25 19:29:49 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

static int		ft_lldi(long long n, int *c)
{
	if (n < 0)
		ft_putchar('-');
	(*c) = n < 0 ? (*c) + 1 : (*c);
	n = n < 0 ? -n : n;
	if (n >= 10)
	{
		ft_lldi(n / 10, c);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
	(*c)++;
	return (1);
}

static int		ft_cdi(signed char n, int *c)
{
	if (n < 0)
		ft_putchar('-');
	(*c) = n < 0 ? (*c) + 1 : (*c);
	n = n < 0 ? -n : n;
	if (n >= 10)
	{
		ft_cdi(n / 10, c);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
	(*c)++;
	return (1);
}

static int		ft_sdi(short n, int *c)
{
	if (n < 0)
		ft_putchar('-');
	(*c) = n < 0 ? (*c) + 1 : (*c);
	n = n < 0 ? -n : n;
	if (n >= 10)
	{
		ft_sdi(n / 10, c);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
	(*c)++;
	return (1);
}

int				ft_di(va_list ap, unsigned long f, int *c)
{
	if (f >> 5 & 1)
		return (ft_cdi(va_arg(ap, signed char), c));
	if (f >> 6 & 1)
		return (ft_sdi(va_arg(ap, short), c));
	if (f >> 7 & 1)
		return (ft_lldi(va_arg(ap, long long), c));
	if (f >> 8 & 1)
		return (ft_lldi(va_arg(ap, long), c));
	if (f >> 9 & 1)
		return (ft_lldi(va_arg(ap, intmax_t), c));
	if (f >> 10 & 1)
		return (ft_lldi(va_arg(ap, size_t), c));
	return (ft_lldi(va_arg(ap, int), c));
}
