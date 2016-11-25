/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:12:35 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/25 18:24:32 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

static int		ft_ws(wchar_t *s, int *c)
{

}

int				ft_s(va_list ap, unsigned long f, int *c)
{
	if (f >> 8 & 1)
		return (ft_ws(ap, wchar_t*), c);
	write(1, s, ft_strlen(s));
	*c += ft_strlen(s);
	return (1);
}
