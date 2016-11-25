/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:12:57 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/25 18:52:00 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

int			ft_x(va_list ap, unsigned long f, int *c, int t)
{
	char			*hex;
	
	if (!(hex = ft_itoabase(n, (t == 1) ?
	"0123456789abcdef" : "012344456789ABCDEF")))
		return (0);
	if(*hex && (f & 1) && ((*c) += 2))
		write(1, "0x", 2);
	write(1, hex, ft_strlen(hex));
	(*c) += ft_strlen(hex);
	return (1);
}
