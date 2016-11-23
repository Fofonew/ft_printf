/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:00:19 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/23 13:17:53 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

int			ft_flags(char *s, long f)
{
	if (*s == '#')
		f |= FG 0;
	else if (*s == '0')
		f |= FG 1;
	else if (*s == '-')
		f |= FG 2;
	else if (*s == '+')
		f |= FG 3;
	else if (*s == ' ')
		f |= FG 4;
	else if (*s == 'h' && *(s + 1) == 'h')
		f |= FG 5;
	else if (*s == 'h')
		f |= FG 6;
	else if (*s == 'l' && *(s + 1) == 'l')
		f |= FG 7;
	else if (*s == 'l')
		f |= FG 8;
	else if (*s == 'j')
		f |= FG 9;
	else if (*s == 'z')
		f |= FG 10;
	else
		return (0);
	return ((*s == 'h' && *(s + 1) == 'h') ||
	(*s == 'l' && *(s + 1) == 'l') ? 2 : 1);
}
