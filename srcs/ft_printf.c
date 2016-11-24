/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:19:45 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/24 12:58:25 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

static char			*ft_convert(char *s, va_list ap, int *c)
{
	unsigned long	f[1];
	int				shift;
	int				tmp;

	*f = 0;
	shift = 0;
	if (*s == '%')
	{
		(*c)++;
		write(1, "%", 1);
		return (++s);
	}
	while ((tmp = ft_prim_flags(&s[shift], f)))
		shift += tmp;
	while ((tmp = ft_sec_flags(&s[shift], f)))
		shift += tmp;
	shift += ft_field(&s[shift], f, ap);
	if (!(tmp = ft_format(&s[shift], f, ap, c)))
		return (0);
	else if (tmp != -1)
		return (&s[shift + 1]);
	(*c)++;
	write(1, "%", 1);
	return (s);
}

int					ft_printf(const char *s, ...)
{
	va_list			ap;
	int				c[1];

	*c = 0;
	va_start(ap, s);
	while (*s)
		if (*s == '%')
		{
			if (!(s = ft_convert((char*)(s + 1), ap, c)))
				return (-1);
		}
		else
		{
			(*c)++;
			write(1, s++, 1);
		}
	va_end(ap);
	return (*c);
}
