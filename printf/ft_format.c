/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:50:56 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/26 15:23:26 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*ft_cast_int(char s, va_list ap, long long f, int *c)
{
	if (f >> 5 & 1)
		return (ft_con_int(s, (signed char)va_arg(ap, int), f, c));
	if (f >> 6 & 1)
		return (ft_con_int(s, (short)va_arg(ap, int), f, c));
	if (f >> 7 & 1)
		return (ft_con_int(s, va_arg(ap, long long), f, c));
	if (f >> 8 & 1)
		return (ft_con_int(s, va_arg(ap, long), f, c));
	if (f >> 9 & 1)
		return (ft_con_int(s, va_arg(ap, intmax_t), f, c));
	if (f >> 10 & 1)
		return (ft_con_int(s, va_arg(ap, size_t), f, c));
	return (ft_con_int(s, va_arg(ap, int), f, c));
}

static char		*ft_cast_uns(char s, va_list ap, long long f, int *c)
{
	if (f >> 5 & 1)
		return (ft_con_uns(s, (unsigned char)va_arg(ap, unsigned int), f, c));
	if (f >> 6 & 1)
		return (ft_con_uns(s, (unsigned short)va_arg(ap, unsigned int), f, c));
	if (f >> 7 & 1)
		return (ft_con_uns(s, va_arg(ap, unsigned long long), f, c));
	if (f >> 8 & 1)
		return (ft_con_uns(s, va_arg(ap, unsigned long), f, c));
	if (f >> 9 & 1)
		return (ft_con_uns(s, va_arg(ap, uintmax_t), f, c));
	if (f >> 10 & 1)
		return (ft_con_uns(s, va_arg(ap, size_t), f, c));
	return (ft_con_uns(s, va_arg(ap, unsigned int), f, c));
}

static char		*ft_cast_dbl(char s, va_list ap, long long f, int *c)
{
	if (f >> 11 & 1)
		return (ft_con_dbl(s, va_arg(ap, long double), f, c));
	return (ft_con_dbl(s, va_arg(ap, double), f, c));
}

static void		ft_cast_ptr(va_list ap, long long f, int *c)
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

int				ft_format(char *s, long long f, va_list ap, int *c)
{
	char	*r;
	int		l;

	if (*s == 'd' || *s == 'i')
		r = ft_cast_int(*s, ap, f, c);
	if (*s == 'u' || *s == 'o' || *s == 'x' || *s == 'X')
		r = ft_cast_uns(*s, ap, f, c);
	if (*s == 'f' || *s == 'F' || *s == 'e' || *s == 'E' || *s == 'g' ||
	*s == 'G' || *s == 'a' || *s == 'A')
		r = ft_cast_dbl(*s, ap, f, c);
	if (*s == 'n')
		return (ft_cast_ptr(ap, f, c));
	if (!r)
		return (-1);
	l = ft_strlen(r);
	while ((l < (int)(f >> 12)) && !(f >> 2 & 1) && (l += 1))
		ft_putchar((f >> 1 & 1 ? '0' : ' '));
	ft_putstr(s);
	while ((l < (int)(f >> 12)) && (f >> 2 & 1) && (l += 1))
		ft_putchar((f >> 1 & 1 ? '0' : ' '));
	(*c) += l;
	return (1);
}
