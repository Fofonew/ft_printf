/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 18:07:48 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/26 18:09:40 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_cast_int(va_list ap, long long f)
{
	if (f >> 5 & 1)
		return (ft_con_int((signed char)va_arg(ap, int)));
	if (f >> 6 & 1)
		return (ft_con_int((short)va_arg(ap, int)));
	if (f >> 7 & 1)
		return (ft_con_int(va_arg(ap, long long)));
	if (f >> 8 & 1)
		return (ft_con_int(va_arg(ap, long)));
	if (f >> 9 & 1)
		return (ft_con_int(va_arg(ap, intmax_t)));
	if (f >> 10 & 1)
		return (ft_con_int(va_arg(ap, size_t)));
	return (ft_con_int(va_arg(ap, int)));
}

char		*ft_cast_uns(char s, va_list ap, long long f)
{
	if (f >> 5 & 1)
		return (ft_con_uns(s, (unsigned char)va_arg(ap, unsigned int)));
	if (f >> 6 & 1)
		return (ft_con_uns(s, (unsigned short)va_arg(ap, unsigned int)));
	if (f >> 7 & 1)
		return (ft_con_uns(s, va_arg(ap, unsigned long long)));
	if (f >> 8 & 1)
		return (ft_con_uns(s, va_arg(ap, unsigned long)));
	if (f >> 9 & 1)
		return (ft_con_uns(s, va_arg(ap, uintmax_t)));
	if (f >> 10 & 1)
		return (ft_con_uns(s, va_arg(ap, size_t)));
	return (ft_con_uns(s, va_arg(ap, unsigned int)));
}

char		*ft_cast_dbl(char s, va_list ap, long long f)
{
	if (f >> 11 & 1)
		return (ft_con_dbl(s, va_arg(ap, long double), f));
	return (ft_con_dbl(s, va_arg(ap, double), f));
}
