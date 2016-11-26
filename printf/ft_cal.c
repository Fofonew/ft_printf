/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:56:27 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/26 19:26:08 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_itoabase_uns(unsigned long long n, int b, int t)
{
	char				*s;
	unsigned long long	n2;
	int					l;

	l = 1;
	n2 = n;
	while (n2 >= (unsigned long long)b && (n2 /= b))
		l++;
	if (!(s = ft_strnew(l--)))
		return (0);
	while (n >= (unsigned long long)b)
	{
		s[l--] = !t ?
		("0123456789abcdef")[n % b] : ("0123456789ABCDEF")[n % b];
		n /= b;
	}
	s[l--] = !t ? ("0123456789abcdef")[n % b] :
	("0123456789ABCDEF")[n % b];
	return (s);
}
