/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:47:54 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/24 16:09:57 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

int			ft_o(int n, unsigned long f, int *c)
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

/*int			ft_O(char *s, unsigned long f, int *c)
{
}*/

int			ft_u(unsigned int n, unsigned long f, int *c)
{
	ft_putunbr(n);
	(*c) += 1;
	while ((n /= 10) * 10 >= 10 && (*c)++);
	f = 0;
	return (1);
}

/*int			ft_U(char *s, unsigned long f, int *c)
{
}*/

int			ft_x(int n, unsigned long f, int *c)
{
	char			*hex;
	
	if (!(hex = ft_itoabase(n, "0123456789abcdef")))
		return (0);
	if(*hex && (f & 1) && ((*c) += 2))
		write(1, "0x", 2);
	write(1, hex, ft_strlen(hex));
	(*c) += ft_strlen(hex);
	free(hex);
	return (1);
}
