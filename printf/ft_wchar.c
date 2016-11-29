/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:45:26 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/29 15:45:38 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_wchlen(wchar_t *s, int mod)
{
	int		l;

	l = 0;
	while (*s != L'\0')
	{
		if (*s < 0x80)
			l += 1;
		else if (*s < 0x800)
			l += mod ? 2 : 1;
		else if (*s < 0x10000)
			l += mod ? 3 : 1;
		else
			l += mod ? 4 : 1;
		s++;
	}
	return (l);
}

static void		ft_putwchar(wchar_t c)
{
	if (c < 0x80)
		ft_putchar(c);
	else if (c < 0x800)
	{
		ft_putchar(0xC0 | (c >> 6));
		ft_putchar(0x80 | (c & 0x3F));
	}
	else if (c < 0x10000)
	{
		ft_putchar(0xE0 | (c >> 12));
		ft_putchar(0x80 | (c >> 6 & 0x3F));
		ft_putchar(0x80 | (c & 0x3F));
	}
	else
	{
		ft_putchar(0xF0 | (c >> 18));
		ft_putchar(0x80 | (c >> 12 & 0x3F));
		ft_putchar(0x80 | (c >> 6 & 0x3F));
		ft_putchar(0x80 | (c & 0x3F));
	}
}

static void		ft_putwstr(wchar_t *s, int n)
{
	while (n--)
		ft_putwchar(*s++);
}

static int		ft_out_wch(char s, wchar_t *r, long long *f, int *c)
{
	int l;
	int	el;

	if (!r)
		r = L"(null)";
	l = (s == 'c' || s == 'C') && !*r ? 1 : ft_wchlen(r, 1);
	l = (s == 'S' || s == 's') && f[2] >= 0 && f[2] <= l ? f[2] : l;
	el = !*r ? 1 : ft_wchlen(r, 0);

	while ((l < f[1]) && !(*f >> 2 & 1) && (l += 2))
		write(1, (*f >> 1 & 1 && (f[2] == -1 || f[2] >= l)) ? "0" : " ", 1);

	ft_putwstr(r, s == 'c' || s == 'C' ? 1 : el);

	while ((l < f[1]) && (l += 2))
		write(1, " ", 1);

	(*c) += l;
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
