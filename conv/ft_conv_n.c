/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:16:56 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/25 18:15:30 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_conv_n(va_list ap, unsigned long f, int *c)
{
	if (f >> 5 & 1)
		*(va_arg(ap, signed char*)) = (signed char)*c;
	else if (f >> 6 & 1)
		*(va_arg(ap, short*)) = (short)*c;
	else if (f >> 7 & 1)
		*(va_arg(ap, long long*)) = (long long)*c;
	else if (f >> 8 & 1)
		*(va_arg(ap, long*)) = (long)*c;
	else if (f >> 9 & 1)
		*(va_arg(ap, intmax_t*)) = (intmax_t)*c;
	else if (f >> 10 & 1)
		*(va_arg(ap, size_t*)) = (size_t)*c;
	else
		*(va_arg(ap, signed char*)) = *c;
	return (1);
}
