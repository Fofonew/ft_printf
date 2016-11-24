/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:11:12 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/24 12:58:09 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

int			ft_field(char *s, unsigned long *f, va_list ap)
{
	unsigned long	m;
	unsigned long	p;
	int				i;

	m = 0;
	i = *s == '*' ? 1 : 0;
	if (*s == '*')
		m = va_arg(ap, int);
	else
		while (s[i] >= '0' && s[i] <= '9')
			m += m * 9 + s[i++] - '0';
	if (m != 0)
		*f |= (m << MIN);
	p = 0;
	if (s[i] == '.' && s[i + 1] == '*' && (i += 2))
		p = va_arg(ap, int);
	else if (s[i] == '.' && (i++))
		while (s[i] >= '0' && s[i] <= '9')
			p += p * 9 + s[i++] - '0';
	if (p != 0)
		*f |= (p << PRE);
	return (i);
}
