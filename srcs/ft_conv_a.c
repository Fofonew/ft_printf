/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:41:41 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/24 21:48:26 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

int			ft_s(char *s, unsigned long f, int *c)
{
	write(1, s, ft_strlen(s));
	*c += ft_strlen(s);
	f = 0;
	return (1);
}

/*int			ft_S(wchar_t *s, unsigned long f, int *c)
{

	f = 0;
	(*c) += wcslen(s);
	while (*s)
		write(1, s++, 1);
	return (1);
}*/

int			ft_p(void *p, unsigned long f, int *c)
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

int			ft_di(long long n, unsigned long f, int *c)
{
	long long	n2;

	ft_putnbr(n);
	n2 = n < 0 ? -n : n;
	(*c) += n < 0 ? 2 : 1;
	while ((n2 /= 10) * 10 >= 10 && (*c)++);
	f = 0;
	return (1);
}

/*int			ft_D(int n, unsigned long f, int *c)
{
	
}*/
