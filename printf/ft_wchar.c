/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:45:26 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/29 17:54:34 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_out_wch(char s, wchar_t *r, long long *f, int *c)
{
	/*int l;

	if (!r)
		r = L"(null)";
	
	l = (s == 'c' || s == 'C') && !*r ? 1 : ft_wchlen(r, -1);
	l = (s == 'S' || s == 's') && f[2] >= 0 && f[2] < l ? f[2] : l;
	el = l;
	while ((l < f[1]) && !(*f >> 2 & 1) && (l += 1))
		write(1, *f >> 1 & 1 ? "0" : " ", 1);

	ft_putwstr(r, s == 'c' || s == 'C' ? 1 : );

	while ((l < f[1]) && (l += 1))
		write(1, " ", 1);

	(*c) += l;*/
	s = 0;
	r = 0;
	f = 0;
	c = 0;
	return (1);
}

int				ft_cast_wch(char s, va_list ap, long long *f, int *c)
{
	wchar_t		r[2];

	r[1] = L'\0';
	if (s == 'C' || s == 'c')
	{
		*r = va_arg(ap, wint_t);
		return (ft_out_wch(s, r, f, c));
	}
	return (ft_out_wch(s, va_arg(ap, wchar_t*), f, c));
}
