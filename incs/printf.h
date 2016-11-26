/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:02:18 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/26 15:10:10 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"

int			ft_format(char *s, long long f, va_list ap, int *c);
char		*ft_con_int(char s, long long i, long long f, int *c);
char		*ft_con_uns(char s, unsigned long long i, long long f, int *c);
char		*ft_con_dbl(char s, long double i, long long f, int *c);

#endif
