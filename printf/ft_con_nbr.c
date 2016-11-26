/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_con_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:46:07 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/26 17:56:23 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

char		*ft_con_int(long long i)
{
	unsigned long long	i2;
	char				*r;
	int					l;

	i2 = i < 0 ? -i : i;
	l = 1;
	while (i2 >= 10 && (i2 /= 10))
		l++;
	if (!(r = ft_strnew(l-- + (i < 0))))
		return (0);
	i2 = i < 0 ? -i : i;
	while (i2 >= 10)
	{
		r[l-- + (i < 0)] = (char)(i2 % 10 + '0');
		i2 /= 10;
	}
	r[l-- + (i < 0)] = (char)(i2 % 10 + '0');
	*r = i < 0 ? '-' : *r;
	return (r);
}

char		*ft_con_uns(char s, unsigned long long i)
{
	if (s == 'u')
		return (ft_itoabase_uns(i, 10, 0));
	if (s == 'o')
		return (ft_itoabase_uns(i, 8, 0));
	if (s == 'x')
		return (ft_itoabase_uns(i, 16, 0));
	if (s == 'X')
		return (ft_itoabase_uns(i, 16, 1));
	return (0);
}

char		*ft_con_dbl(char s, long double i, long long f)
{
	s = 0;
	i = 0;
	f = 0;
	return (0);
}

int			ft_con_ptr(va_list ap, long long f, int *c)
{
	if (f >> 5 & 1)
		*(signed char*)va_arg(ap, int*) = *c;
	else if (f >> 6 & 1)
		*(short*)va_arg(ap, int*) = *c;
	else if (f >> 7 & 1)
		*va_arg(ap, long long*) = *c;
	else if (f >> 8 & 1)
		*va_arg(ap, long*) = *c;
	else if (f >> 9 & 1)
		*va_arg(ap, intmax_t*) = *c;
	else if (f >> 10 & 1)
		*va_arg(ap, size_t*) = *c;
	else
		*va_arg(ap, int*) = *c;
	return (1);
}
