/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:11:37 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/24 21:58:28 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"
#include <stdio.h>

int				ft_format(char *s, unsigned long f, va_list ap, int *c)
{
	/*if (*s == 'S' || (*s == 's' && f >> 8 & 1))
		return (ft_ws(va_arg(ap, wchar_t*), f, c));*/
	if (*s == 's')
		return (ft_s(va_arg(ap, char*), f, c));


	if (*s == 'p')
		return (ft_p(va_arg(ap, void*), f, c));


	/*if ((*s == 'd' || *s == 'i') && (f >> 5 & 1))
		return (ft_hhdi(va_arg(ap, signed char), f, c));*/
	/*if ((*s == 'd' || *s == 'i') && (f >> 6 & 1))
		return (ft_hdi(va_arg(ap, short), f, c));*/
	if ((*s == 'd' || *s == 'i') && (f >> 7 & 1))
		return (ft_di(va_arg(ap, long long), f, c));
	if ((*s == 'd' || *s == 'i') && (f >> 8 & 1))
		return (ft_di((long long)va_arg(ap, long), f, c));
	/*if ((*s == 'd' || *s == 'i') && (f >> 9 & 1))
		return (ft_jdi(va_arg(ap, intmax_t), f, c));
	if ((*s == 'd' || *s == 'i') && (f >> 10 & 1))
		return (ft_zdi(va_arg(ap, size_t), f, c));
	if ((*s == 'd' || *s == 'i') && (f >> 8 & 1))
		return (ft_tdi(va_arg(ap, ptrdiff_t), f, c));*/
	if ((*s == 'd' || *s == 'i'))
		return (ft_di((long long)va_arg(ap, int), f, c));
	/*if (*s == 'D')
		return (ft_D(va_arg(ap, unsigned int), f, c));*/


	/*if (*s == 'o')
		return (ft_o(va_arg(ap, int), f, c));
	if (*s == 'O') unsigned octal
		return (ft_O(va_arg(ap, void), f, c));*/


	if (*s == 'u')
		return (ft_u(va_arg(ap, int), f, c));
	/*if (*s == 'U') unsigned decimal
		return (ft_U(va_arg(ap, void), f, c));*/


	if (*s == 'x')
		return (ft_x(va_arg(ap, int), f, c));
	if (*s == 'X')
		return (ft_X(va_arg(ap, int), f, c));


	if (*s == 'c')
		return (ft_c(va_arg(ap, int), f, c));
	/*if (*s == 'C') wint_t
		return (ft_wc(va_arg(ap, wchar_t), f, c));*/
	return (-1);
}
