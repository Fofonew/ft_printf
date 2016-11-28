/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:45:26 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/28 18:00:10 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_out_wch(char s, wchar_t *r, long long *f, int *c)
{
	/*int l;

	l = s == 'c' ? 1 : ft_strlen(r);
	if (*f >> 1 & 1)
		if (*r == '-' && (r = ft_strcpy(r, r + 1)))
			write(1, "-", 1);
	while ((l < f[1]) && !(*f >> 2 & 1) && (l += 1))
		write(1, (*f >> 1 & 1 && (f[2] == -1 || f[2] >= l)) ? "0" : " ", 1);
	write(1, r, s == 'c' ? 1 : ft_strlen(r));
	while ((l < f[1]) && (l += 1))
		write(1, " ", 1);
	(*c) += l;*/
	s = 0;
	r = 0;
	f = 0;
	c = 0;
	return (1);
}

static int		ft_pre_wch(char s, wchar_t *r, long long *f, int *c)
{
	/*int		l;

	if (!r)
		r = "(null)";
	l = s == 'c' ? 1 : ft_strlen(r);
	if (s == 's' && f[2] >= 0 && f[2] <= l)
		r = ft_strndup(r, f[2]);*/
	return (ft_out_wch(s, r, f, c));
}

int				ft_cast_wch(char s, va_list ap, long long *f, int *c)
{

	return (ft_pre_wch(s, va_arg(ap, wchar_t*), f, c));
}
