/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:13:22 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/25 18:20:39 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

static int		ft_wc(wint_t n, int *c)
{

}

int				ft_c(va_list ap, unsigned long f, int *c)
{
	if (f >> 8 & 1)
		return (ft_wc(va_arg(ap, wint_t), c));
	ft_putchar(va_arg(ap, char));
	(*c)++;
	return (1);
}
