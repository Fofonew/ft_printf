/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:23:17 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/25 17:38:24 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

int			ft_p(va_list ap, unsigned long f, int *c)
{
	char	*hex;

	write(1, "0x7fff", 6);
	if (!(hex = ft_itoabase((int)p, "0123456789abcdef")))
		return (0);
	write(1, hex, ft_strlen(hex));
	(*c) += 6 + ft_strlen(hex);
	free(hex);
	f = 0;
	return (1);
}
