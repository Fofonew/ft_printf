/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:19:45 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/27 20:53:10 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int			ft_fields(char *s, long long *f, va_list ap)
{
	int		m;
	int		p;
	int		i;

	m = 0;
	i = *s == '*' ? 1 : 0;
	if (*s == '*')
		m = va_arg(ap, int);
	else
		while (s[i] >= '0' && s[i] <= '9')
			m += m * 9 + s[i++] - '0';
	f[1] = m;
	p = -1;
	if (s[i] == '.' && s[i + 1] == '*' && (i += 2))
		p = va_arg(ap, int);
	else if (s[i] == '.' && (i += 1) && !(p = 0))
		while (s[i] >= '0' && s[i] <= '9')
			p += p * 9 + s[i++] - '0';
	f[2] = p;
	return (i);
}

static char			*ft_parse(char *s, va_list ap, int *c)
{
	long long	f[3];
	int			p;
	int			r;

	f[0] = 0;
	p = 0;
	r = 0;
	if (!*s)
		return (s);
	while ((s[p] == '#' && (*f |= 1)) || (s[p] == '0' && (*f |= 1 << 1)) ||
	(s[p] == '-' && (*f |= 1 << 2)) || (s[p] == '+' && (*f |= 1 << 3)) ||
	(s[p] == ' ' && (*f |= 1 << 4)))
		++p;
	p += ft_fields(&s[p], f, ap);
	if ((s[p] == 'h' && (s[p + 1] == 'h') && (*f |= 1 << 5)) || ((s[p] ==
	'h') && (*f |= 1 << 6)) || ((s[p] == 'l' && s[p + 1] == 'l') && (*f |=
	1 << 7)) || ((s[p] == 'l') && (*f |= 1 << 8)) || ((s[p] == 'j') && (*f |=
	1 << 9)) || ((s[p] == 'z') && (*f |= 1 << 10)) || ((s[p] == 'L') &&
	(*f |= 1 << 11)))
		p += ((*f >> 5 & 1) || (*f >> 7 & 1)) ? 2 : 1;
	if (!s[p])
		return (&s[p]);
	if (s[p] && !(r = ft_format(&s[p], f, ap, c)))
		return (0);
	else if (!s[p] || r != -1)
		return (&s[p + 1]);
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
			if (!(s = ft_parse((char*)(s + 1), ap, c)))
				return (-1);
		}
		else
		{
			((*c) += 1);
			write(1, s++, 1);
		}
	va_end(ap);
	return (*c);
}
