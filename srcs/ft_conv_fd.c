/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:22:58 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/25 18:16:04 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

int			ft_conv_fd(va_list ap, unsigned long f, int *c)
{
	int		fd;
	int		rd;
	char	buff[33];

	fd = va_arg(ap, int);
	while ((rd = read(fd, buff, 32)))
	{
		if (rd == -1)
			return (-1);
		buff[rd] = '\0';
		(*c) += rd;
		ft_putstr(buff);
	}
	return (1);
}
