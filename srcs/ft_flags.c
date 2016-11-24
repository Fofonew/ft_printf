/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:58:15 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/24 21:52:37 by tberthie         ###   ########.fr       */
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
	int		flag;

	flag = 0;
	if (*s == 'h' && *(s + 1) == 'h')
		flag = 5;
	else if (*s == 'h')
		flag = 6;
	else if (*s == 'l' && *(s + 1) == 'l')
		flag = 7;
	else if (*s == 'l')
		flag = 8;
	else if (*s == 'j')
		flag = 9;
	else if (*s == 'z')
		flag = 10;
	if (!flag || (*f >> 5 & 63))
		return (0);
	*f |= 1 << flag;
	return ((*s == 'h' && *(s + 1) == 'h') ||
	(*s == 'l' && *(s + 1) == 'l') ? 2 : 1);
}
