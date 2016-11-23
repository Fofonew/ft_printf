/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:19:45 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/23 13:18:17 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

static char			*ft_process(char *s)
{
	long			f;
	unsigned int	shift;
	unsigned int	tmp;

	f = 0;
	shift = 0;
	if (*s == '%')
	{
		write(1, "%", 1);
		return (&(s[shift + 1]));
	}
	while ((tmp = ft_flags(&s[shift], f)))
		shift += tmp;
	if ((tmp = ft_field(&s[shift])))
		shift += tmp;
	if ((tmp = ft_flags(&s[shift], f)))
		return (&s[shift + 1]);
	return (0);
}

int					ft_printf(const char *s, ...)
{
	va_list			ap;

	va_start(ap, s);
	while (*s)
	{
		if (*s == '%' && !(s = ft_process((char*)(s + 1))))
			return (-1);
		if (*s)
			write(1, s, 1);
		s++;
	}
	va_end(ap);
	return (0);
}
