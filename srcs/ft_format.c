/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:11:37 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/24 17:21:44 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"
#include <stdio.h>

int				ft_format(char *s, unsigned long f, va_list ap, int *c)
{
	if (*s == 's')
		return (ft_s(va_arg(ap, char*), f, c));
	/*if (*s == 'S') wchar_t*
		return (ft_S(va_arg(ap, wchar_t*), f, c));*/
	if (*s == 'p')
		return (ft_p(va_arg(ap, void*), f, c));
	if (*s == 'd' || *s == 'i')
		return (ft_di(va_arg(ap, int), f, c));
	/*iif (*s == 'D') unsigned 
		return (ft_D(va_arg(ap, void), f, c));*/
	if (*s == 'o')
		return (ft_o(va_arg(ap, int), f, c));
	/*if (*s == 'O') unsigned octal
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
		return (ft_C(va_arg(ap, void), f, c));*/
	return (-1);
}
