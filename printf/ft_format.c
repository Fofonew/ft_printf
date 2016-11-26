/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:50:56 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/26 20:17:51 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_flags_len(char s, char *r, long long f, int l)
{
	if (s == 'p' || ((f & 1) && (s == 'x' || s == 'X') && *r != 0))
		l += 2;
	else if ((f & 1) && (s == 'o') && *r != 0)
		l += 1;
	else if (f >> 3 & 1 && *r != '-' && (s == 'd' || s == 'i'))
		l += 1;
	else if (*r != '-' && (f >> 4 & 1))
		l += 1;
	if (*r == '-' && l < (int)(f >> 12) && !(f >> 2 & 1) && (*r = '0'))
		l += 1;
	return (l);
}

static void		ft_out_flags(char s, char *r, long long f, int l)
{
	if (s == 'p' || ((f & 1) && (s == 'x' || s == 'X') && *r != 0))
		write(1, "0x", 2);
	else if ((f & 1) && (s == 'o') && *r != 0)
		write(1, "0", 1);
	else if (f >> 3 & 1 && *r != '-' && (s == 'd' || s == 'i'))
		write(1, "+", 1);
	else if (*r != '-' && (f >> 4 & 1))
		write(1, " ", 1);
	if (*r == '-' && l < (int)(f >> 12) && !(f >> 2 & 1) && (*r = '0'))
		write(1, "-", 1);
}

static int		ft_out(char *s, char *r, long long f, int *c)
{
	int l;

	l = ft_strlen(r);
	l = ft_flags_len(*s, r, f, l);
	if (f >> 1 & 1)
		ft_out_flags(*s, r, f, l);
	while ((l < (int)(f >> 12)) && !(f >> 2 & 1) && (l += 1))
		write(1, (f >> 1 & 1 ? "0" : " "), 1);
	if (!(f >> 1 & 1))
		ft_out_flags(*s, r, f, l);
	write(1, r, ft_strlen(r));
	//dec point #
	while ((l < (int)(f >> 12)) && (l += 1))
		write(1, " ", 1);
	(*c) += l;
	return (1);
}

int				ft_format(char *s, long long f, va_list ap, int *c)
{
	char	*r;

	r = 0;
	if (*s == '%')
		r = "%";
	if (*s == 'd' || *s == 'i')
		r = ft_cast_int(ap, f);
	if (*s == 'u' || *s == 'o' || *s == 'x' || *s == 'X')
		r = ft_cast_uns(*s, ap, f);
	if (*s == 'f' || *s == 'F' || *s == 'e' || *s == 'E' || *s == 'g' ||
	*s == 'G' || *s == 'a' || *s == 'A')
		r = ft_cast_dbl(*s, ap, f);
	if (*s == 'p')
		r = ft_itoabase_uns((unsigned long long)va_arg(ap, void*),16, 0);
	r = *s == 's' ? va_arg(ap, char*) : r;
	if (*s == 'c' && (r = ft_strnew(1)))
		*r = va_arg(ap, int);
	if (*s == 'n')
		return (ft_con_ptr(ap, f, c));
	if (!r)
		return (-1);
	return (ft_out(s, r, f, c));
}
