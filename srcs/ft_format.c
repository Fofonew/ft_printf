/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:11:37 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/25 18:11:46 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

int				ft_format(char *s, unsigned long f, va_list ap, int *c)
{
	if (*s == 's' || *s == 'S')
		return (ft_s(ap, f, c));
	if (*s == 'p')
		return (ft_p(ap, f, c));
	if ((*s == 'd' || *s == 'i'))
		return (ft_di(ap, f, c));
	if (*s == 'D')
		return (ft_dd(ap, f, c));
	if (*s == 'o')
		return (ft_o(ap, f, c));
	if (*s == 'O')
		return (ft_oo(ap, f, c));
	if (*s == 'u')
		return (ft_u(ap, f, c));
	if (*s == 'U')
		return (ft_uu(ap, f, c));
	if (*s == 'x' || *s == 'X')
		return (ft_x(ap, f, c, (*s == 'x') ? 0 : 1));
	if (*s == 'c' || *s == 'C')
		return (ft_c(ap, f, c));
	if (*s == 'e' || *s == 'E')
		return (ft_e(ap, f, c, (*s == 'e') ? 0 : 1));
	if (*s == 'f' || *s == 'F')
		return (ft_f(ap, f ,c , (*s == 'f') ? 0 : 1));
	if (*s == 'g' || *s == 'G')
		return (ft_g(ap, f, c, (*s == 'g') ? 0 : 1));
	if (*s == 'a' || *s == 'A')
		return (ft_a(ap, f, c, (*s == 'a') ? 0 : 1));
	if (*s == 'n')
		return (ft_n(ap, f, c));
	if (*s == 'b')
		return (ft_b(ap, f, c));
	if (*s == 'r')
		return (ft_r(ap, f, c));
	if (*s == 'k')
		return (ft_k(ap, f, c));
	if (*s == 'f' && *(s + 1) == 'd')
		return (ft_fd(ap, f, c));
	return (-1);
}
