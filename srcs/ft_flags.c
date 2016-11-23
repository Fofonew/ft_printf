/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:00:19 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/23 16:40:33 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

int			ft_prim_flags(char *s, unsigned long *f)
{
	if (*s == '#')
		*f |= 1;
	else if (*s == '0')
		*f |= 1 << 1;
	else if (*s == '-')
		*f |= 1 << 2;
	else if (*s == '+')
		*f |= 1 << 3;
	else if (*s == ' ')
		*f |= 1 << 4;
	else
		return (0);
	return (1);
}

int			ft_sec_flags(char *s, unsigned long *f)
{
	if (*s == 'h' && *(s + 1) == 'h') // set for single use
		*f |= 1 << 5;
	else if (*s == 'h')
		*f |= 1 << 6;
	else if (*s == 'l' && *(s + 1) == 'l')
		*f |= 1 << 7;
	else if (*s == 'l')
		*f |= 1 << 8;
	else if (*s == 'j')
		*f |= 1 << 9;
	else if (*s == 'z')
		*f |= 1 << 10;
	else
		return (0);
	return ((*s == 'h' && *(s + 1) == 'h') ||
	(*s == 'l' && *(s + 1) == 'l') ? 2 : 1);
}
