/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:12:42 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/25 18:14:09 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

int			ft_o(va_list ap, unsigned long f, int *c)
{
	char	*oct;

	if (!(oct = ft_itoabase(n, "01234567")))
		return (0);
	if (*oct && (f & 1) && (*c)++)
		write(1, "0", 1);
	write(1, oct, ft_strlen(oct));
	(*c) += ft_strlen(oct);
	free(oct);
	return (1);
}
