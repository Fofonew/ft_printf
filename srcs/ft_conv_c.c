/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:41:41 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/24 15:28:13 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

int			ft_X(int n, unsigned long f, int *c)
{
	char			*hex;

	if (!(hex = ft_itoabase(n, "0123456789ABCDEF")))
		return (0);
	if((f & 1) && ((*c) += 2))
		write(1, "0X", 2);
	write(1, hex, ft_strlen(hex));
	(*c) += ft_strlen(hex);
	return (1);
}

int			ft_c(int n, unsigned long f, int *c)
{
	ft_putchar((char)n);
	(*c)++;
	f = 0;
	return (1);
}

/*int		ft_C()
{

}*/
