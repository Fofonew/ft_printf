/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:11:37 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/23 17:24:41 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

int		ft_string(char *s, unsigned long *f, int *c)
{
	if (!s)
		return (0);
	write(1, s, ft_strlen(s));
	*c += ft_strlen(s);
	f = 0;
	return (1);
}

int		ft_format(char *s, unsigned long *f, va_list ap, int *c)
{
	/*if (*f >> 1 && 1)*/
	if (*s == 's')
		return (ft_string(va_arg(ap, char*), f, c));
	return (-1);
}
