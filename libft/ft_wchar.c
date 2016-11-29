/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:52:19 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/29 17:55:28 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_charwlen(wchar_t c)
{
	if (c > 0x10000)
		return (c > 200000 ? 4 : 3);
	return (c > 0x800 ? 2 : 1);
}

int		ft_strwlen(wchar_t *s)
{
	int		l;

	l = 0;
	while (*s++)
		l++;
	return (l);
}

void	ft_putwchar(wchar_t c)
{
	ft_putchar(c > 0x800 ? 0x80 | (c & 0x3F) : c);
	if (c > 0x800)
		ft_putchar(c > 0x10000 ? 0x80 | (c >> 6 & 0x3F) :
		0xC0 | (c >> 6));
	if (c > 0x10000)
		ft_putchar(c > 0x200000 ? 0x80 | (c >> 12 & 0x3F) :
		0xE0 | (c >> 12));
	if (c > 0x200000)
		ft_putchar(0xF0 | (c >> 18));
}

void	ft_putwstr(wchar_t *s)
{
	while (*s)
		ft_putwchar(*s++);
}
