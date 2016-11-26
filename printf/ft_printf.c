/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:19:45 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/26 20:17:27 by tberthie         ###   ########.fr       */
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
	if (m != 0)
		*f |= (m << 12);
	p = 0;
	if (s[i] == '.' && s[i + 1] == '*' && (i += 2))
		p = va_arg(ap, int);
	else if (s[i] == '.' && (i++))
		while (s[i] >= '0' && s[i] <= '9')
			p += p * 9 + s[i++] - '0';
	if (p != 0)
		*f |= (p << 28);
	return (i);
}

static char			*ft_parse(char *s, va_list ap, int *c)
{
	long long	f[1];
	int			p;
	int			r;

	*f = 0;
	p = 0;
	while ((s[p] == '#' && (*f |= 1)) || (s[p] == '0' && (*f |= 1 << 1)) ||
	(s[p] == '-' && (*f |= 1 << 2)) || (s[p] == '+' && (*f |= 1 << 3)) ||
	(s[p] == ' ' && (*f |= 1 << 4)))
		++p;
	p += ft_fields(&s[p], f, ap);
	if ((((*s == 'h' && *(s + 1) == 'h') && (*f |= 1 << 5)) || ((*s ==
	'h') && (*f |= 1 << 6)) || ((*s == 'l' && *(s + 1) == 'l') && (*f |=
	1 << 7)) || ((*s == 'l') && (*f |= 1 << 8)) || ((*s == 'j') && (*f |=
	1 << 9)) || ((*s == 'z') && (*f |= 1 << 10)) || ((*s == 'L') &&
	(*f |= 1 << 11))))
		p += ((*f >> 5 & 1) || (*f >> 7 & 1)) ? 2 : 1;
	if (!(r = ft_format(&s[p], *f, ap, c)))
		return (0);
	else if (r != -1)
		return (&s[p + 1]);
	++(*c);
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
			if (!(s = ft_parse((char*)(s + 1), ap, c)))
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
