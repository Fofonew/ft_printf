/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:58:15 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/25 18:58:20 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

int			ft_flags(char *s, unsigned long *f)
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

int			ft_conv(char *s, unsigned long *f)
{
	int		conv;

	conv = 0;
	if (*s == 'h' && *(s + 1) == 'h')
		conv = 5;
	else if (*s == 'h')
		conv = 6;
	else if (*s == 'l' && *(s + 1) == 'l')
		conv = 7;
	else if (*s == 'l')
		conv = 8;
	else if (*s == 'j')
		conv = 9;
	else if (*s == 'z')
		conv = 10;
	if (!conv || (*f >> 5 & 63))
		return (0);
	*f |= 1 << conv;
	return ((*s == 'h' && *(s + 1) == 'h') ||
	(*s == 'l' && *(s + 1) == 'l') ? 2 : 1);
}
