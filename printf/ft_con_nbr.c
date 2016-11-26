/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_con_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:46:07 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/26 16:34:47 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

char		*ft_con_int(long long i, long long f)
{
	unsigned long long	i2;
	char				*r;
	int					l;

	i2 = i < 0 ? -i : i;
	l = 1;
	while (i2 >= 10 && (i2 /= 10))
		l++;
	if (!(r = ft_strnew(l-- + ((i < 0) || (f >> 3 & 1) ||
	(f >> 4 & 1)))))
		return (0);
	i2 = i < 0 ? -i : i;
	while (i2 >= 10)
	{
		r[l-- + ((i < 0) || (f >> 3 & 1) || (f >> 4 & 1))] =
		(char)(i2 % 10 + '0');
		i2 /= 10;
	}
	r[l-- + ((i < 0) || (f >> 3 & 1) || (f >> 4 & 1))] = (char)(i2 % 10 + '0');
	*r = (f >> 4 & 1) ? ' ' : *r;
	*r = i < 0 ? '-' : *r;
	*r = i >= 0 && (f >> 3 & 1) ? '+' : *r;
	return (r);
}

char		*ft_con_uns(char s, unsigned long long i, long long f)
{
	if (s == 'u')
		return (ft_itoabase_uns(i, 10, 0, f));
	if (s == 'o')
		return (ft_itoabase_uns(i, 7, 0, f));
	if (s == 'x')
		return (ft_itoabase_uns(i, 16, 0, f));
	if (s == 'X')
		return (ft_itoabase_uns(i, 16, 1, f));
	return (0);
}

char		*ft_con_dbl(char s, long double i, long long f)
{
	s = 0;
	i = 0;
	f = 0;
	return (0);
}
