/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:11:37 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/24 13:05:45 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

static int		ft_s(char *s, unsigned long *f, int *c)
{
	write(1, s, ft_strlen(s));
	*c += ft_strlen(s);
	f = 0;
	return (1);
}

/*static int		ft_S()
{

}*/

static int		ft_p(void *p, unsigned long *f, int *c)
{
	char *hex;

	write(1, "0x7fff", 6);
	p = 0;

	//hex = ft_itoab((unsigned int)p, 16);
	write(1, hex, ft_strlen(hex));
	(*c) += 6 + ft_strlen(hex);
	f = 0;
	return (1);
}

static int		ft_d(int n, unsigned long *f, int *c)
{
	unsigned int	n2;

	ft_putnbr(n);
	n2 = n < 0 ? -n : n;
	(*c) += n < 0 ? 2 : 1;
	while ((n2 /= 10) * 10 >= 10 && (*c)++);
	f = 0;
	return (1);
}

int				ft_format(char *s, unsigned long *f, va_list ap, int *c)
{
	if (*s == 's')
		return (ft_s(va_arg(ap, char*), f, c));
	/*if (*s == 'S')
		return (ft_S(va_arg(ap, char*), f, c));*/
	if (*s == 'p')
		return (ft_p(va_arg(ap, void*), f, c));
	if (*s == 'd')
		return (ft_d(va_arg(ap, int), f, c));
	return (-1);
}
