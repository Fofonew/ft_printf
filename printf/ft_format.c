/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:50:56 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/28 15:26:08 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_flags_len(char s, char *r, long long *f, int l)
{
	if (s == 'p' || ((*f & 1) && (s == 'x' || s == 'X') && *r && *r != '0'))
		l += 2;
	else if ((*f & 1) && (s == 'o'))
		l += 1;
	else if (*f >> 3 & 1 && *r != '-' && (s == 'd' || s == 'i'))
		l += 1;
	else if (*r != '-' && (*f >> 4 & 1) && (s == 'd' || s == 'i'))
		l += 1;
	return (l);
}

static void		ft_out_flags(char s, char *r, long long *f)
{
	if ((*r) && (s == 'p' || ((*f & 1) && (s == 'x' || s == 'X') && *r != '0')))
		write(1, (s == 'X' ? "0X" : "0x"), 2);
	else if ((*f & 1) && (s == 'o'))
		write(1, "0", 1);
	else if (*f >> 3 & 1 && *r != '-' && (s == 'd' || s == 'i'))
		write(1, "+", 1);
	else if (*r != '-' && (*f >> 4 & 1) && (s == 'd' || s == 'i'))
		write(1, " ", 1);
}

static int		ft_out(char *s, char *r, long long *f, int *c)
{
	int l;

	l = *s == 'c' ? 1 : ft_strlen(r);
	l = ft_flags_len(*s, r, f, l);

	if (*f >> 1 & 1)
	{
		ft_out_flags(*s, r, f);
		if (*r == '-' && (r = ft_strcpy(r, r + 1)))
			write(1, "-", 1);
	}

	while ((l < f[1]) && !(*f >> 2 & 1) && (l += 1))
		write(1, (*f >> 1 & 1 && (f[2] == -1 || f[2] >= l)) ? "0" : " ", 1);

	if (!(*f >> 1 & 1))
		ft_out_flags(*s, r, f);

	write(1, r, *s == 'c' ? 1 : ft_strlen(r));

	while ((l < f[1]) && (l += 1))
		write(1, " ", 1);

	(*c) += l;
	return (1);
}

static int		ft_pre(char *s, char *r, long long *f, int *c)
{
	int		l;

	if (!r)
		r = "(null)";
	l = *s == 'c' ? 1 : ft_strlen(r);

	if (*s == 's' && f[2] >= 0 && f[2] <= l)
		r = ft_strndup(r, f[2]);

	return (ft_out(s, r, f, c));
}

int				ft_format(char *s, long long *f, va_list ap, int *c)
{
	char	*r;

	r = 0;
	if (*s == '%')
		return (ft_pre(s, "%", f, c));
	else if (*s == 'd' || *s == 'i')
		return (ft_pre(s, ft_cast_int(ap, f), f, c));
	else if (*s == 'u' || *s == 'o' || *s == 'x' || *s == 'X')
		return (ft_pre(s, ft_cast_uns(*s, ap, f), f, c));
	else if (*s == 'f' || *s == 'F' || *s == 'e' || *s == 'E' || *s == 'g' ||
	*s == 'G' || *s == 'a' || *s == 'A')
		return (ft_pre(s, ft_cast_dbl(*s, ap, *f), f, c));
	else if (*s == 'p')
		return (ft_pre(s, ft_itoabase_uns((unsigned long long)va_arg(ap, void*),
		16, 0, *s), f, c));
	else if (*s == 's')
		return (ft_pre(s, va_arg(ap, char*), f, c));
	else if (*s == 'c')
		return ((r = ft_strnew(1)) &&
		(*r = va_arg(ap, int)) != -1 ? ft_pre(s, r, f, c) : 0);
	else if (*s == 'n')
		return (ft_con_ptr(ap, *f, c));
	else
		return (ft_pre(s, ft_strndup(s, 1), f, c));
}
