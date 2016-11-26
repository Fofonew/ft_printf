/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:50:56 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/26 16:27:12 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*ft_cast_int(va_list ap, long long f)
{
	if (f >> 5 & 1)
		return (ft_con_int((signed char)va_arg(ap, int), f));
	if (f >> 6 & 1)
		return (ft_con_int((short)va_arg(ap, int), f));
	if (f >> 7 & 1)
		return (ft_con_int(va_arg(ap, long long), f));
	if (f >> 8 & 1)
		return (ft_con_int(va_arg(ap, long), f));
	if (f >> 9 & 1)
		return (ft_con_int(va_arg(ap, intmax_t), f));
	if (f >> 10 & 1)
		return (ft_con_int(va_arg(ap, size_t), f));
	return (ft_con_int(va_arg(ap, int), f));
}

static char		*ft_cast_uns(char s, va_list ap, long long f)
{
	if (f >> 5 & 1)
		return (ft_con_uns(s, (unsigned char)va_arg(ap, unsigned int), f));
	if (f >> 6 & 1)
		return (ft_con_uns(s, (unsigned short)va_arg(ap, unsigned int), f));
	if (f >> 7 & 1)
		return (ft_con_uns(s, va_arg(ap, unsigned long long), f));
	if (f >> 8 & 1)
		return (ft_con_uns(s, va_arg(ap, unsigned long), f));
	if (f >> 9 & 1)
		return (ft_con_uns(s, va_arg(ap, uintmax_t), f));
	if (f >> 10 & 1)
		return (ft_con_uns(s, va_arg(ap, size_t), f));
	return (ft_con_uns(s, va_arg(ap, unsigned int), f));
}

static char		*ft_cast_dbl(char s, va_list ap, long long f)
{
	if (f >> 11 & 1)
		return (ft_con_dbl(s, va_arg(ap, long double), f));
	return (ft_con_dbl(s, va_arg(ap, double), f));
}

static int		ft_cast_ptr(va_list ap, long long f, int *c)
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

	r = NULL;
	if (*s == 'd' || *s == 'i')
		r = ft_cast_int(ap, f);
	else if (*s == 'u' || *s == 'o' || *s == 'x' || *s == 'X')
		r = ft_cast_uns(*s, ap, f);
	else if (*s == 'f' || *s == 'F' || *s == 'e' || *s == 'E' || *s == 'g' ||
	*s == 'G' || *s == 'a' || *s == 'A')
		r = ft_cast_dbl(*s, ap, f);
	else if (*s == 'n')
		return (ft_cast_ptr(ap, f, c));
	if (!r)
		return (-1);
	l = ft_strlen(r);
	while ((l < (int)(f >> 12)) && !(f >> 2 & 1) && (l += 1))
		ft_putchar((f >> 1 & 1 ? '0' : ' '));
	ft_putstr(r);
	while ((l < (int)(f >> 12)) && (f >> 2 & 1) && (l += 1))
		ft_putchar((f >> 1 & 1 ? '0' : ' '));
	(*c) += l;
	return (1);
}
