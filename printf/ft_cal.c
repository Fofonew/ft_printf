/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:56:27 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/26 16:38:43 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_itoabase_uns(unsigned long long n, int b, int t, long long f)
{
	char				*s;
	unsigned long long	n2;
	int					l;
	int					p;

	l = 1;
	n2 = n;
	p = b == 7 && (f & 1) ? 1 : 0;
	p = b == 16 && (f & 1) ? 2 : p;
	while (n2 >= (unsigned long long)b && (n2 /= b))
		l++;
	if (!(s = ft_strnew(l-- + p + ((f >> 3 & 1) || (f >> 4 & 1)))))
		return (0);
	while (n >= (unsigned long long)b)
	{
		s[l-- + ((f >> 3 & 1) || (f >> 4 & 1))] = !t ?
		("0123456789abcdef")[n % b] : ("0123456789ABCDEF")[n % b];
		n /= b;
	}
	s[l-- + ((f >> 3 & 1) || (f >> 4 & 1))] = !t ? ("0123456789abcdef")[n % b] :
	("0123456789ABCDEF")[n % b];
	*(s + ((f >> 4 & 1) || (f >> 3 & 1))) = p ? '0' : *(s +
	((f >> 4 & 1) || (f >> 3 & 1)));
	*(s + 1 + ((f >> 4 & 1) || (f >> 3 & 1))) = p == 2 ? 'x' : *(s + 1 +
	((f >> 4 & 1) || (f >> 3 & 1)));
	*s = f >> 4 & 1 ? ' ' : *s;
	*s = f >> 3 & 1 ? '+' : *s;
	return (s);
}
