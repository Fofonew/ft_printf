/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:02:18 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/26 18:09:38 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"

int			ft_format(char *s, long long f, va_list ap, int *c);

char		*ft_cast_int(va_list ap, long long f);
char		*ft_cast_uns(char s, va_list ap, long long f);
char		*ft_cast_dbl(char s, va_list ap, long long f);

char		*ft_con_int(long long i);
char		*ft_con_uns(char s, unsigned long long i);
char		*ft_con_dbl(char s, long double i, long long f);
int			ft_con_ptr(va_list ap, long long f, int *c);

char		*ft_itoabase_uns(unsigned long long n, int b, int t);

#endif
