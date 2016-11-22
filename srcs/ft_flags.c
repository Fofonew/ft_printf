/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:00:19 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/22 18:11:13 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

int			ft_flag(char *format, t_flags *flags)
{
	if (!ft_strncmp(format, "#", 1))
		flags->flags[0] = 1;
	else if (!ft_strncmp(format, "0", 1))
		flags->flags[1] = 1;
	else if (!ft_strncmp(format, "-", 1))
		flags->flags[2] = 1;
	else if (!ft_strncmp(format, "+", 1))
		flags->flags[3] = 1;
	else if (!ft_strncmp(format, " ", 1))
		flags->flags[4] = 1;
	else if (!ft_strncmp(format, "hh", 2))
		flags->flags[5] = 1;
	else if (!ft_strncmp(format, "h", 1))
		flags->flags[6] = 1;
	else if (!ft_strncmp(format, "ll", 2))
		flags->flags[7] = 1;
	else if (!ft_strncmp(format, "l", 1))
		flags->flags[8] = 1;
	else if (!ft_strncmp(format, "j", 1))
		flags->flags[9] = 1;
	else if (!ft_strncmp(format, "z", 1))
		flags->flags[10] = 1;
	else
		return (0);
	return (!ft_strncmp(format, "hh", 2) ||
	ft_strncmp(format, "ll", 2) ? 2 : 1);
}
