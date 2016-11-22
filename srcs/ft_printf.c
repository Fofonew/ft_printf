/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:19:45 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/20 17:18:22 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

const char	*ft_process(char *format)
{
	t_flags			*flags;
	unsigned int	shift;
	unsigned int	tmp;

	shift = 0;
	if (!(flags = malloc(sizeof(t_flags))))
		return (0);
	while ((tmp = ft_flag(&format[shift], flags)))
		shift += tmp;
	if ((tmp = ft_field(format)))
		shift += tmp;
	if ((tmp = ft_format(format)))
		return (&format[shift + 1]);
	return (format);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	while (*format)
			if (*format++ == '%')
				if (!(format = ft_process((char*)format)))
					return (-1);
	va_end(ap);
	return (0);
}
