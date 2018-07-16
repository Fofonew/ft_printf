/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 14:34:59 by doriol            #+#    #+#             */
/*   Updated: 2018/07/02 14:35:03 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"

int			ft_format(char *s, long long *f, va_list ap, int *c);

char		*ft_cast_int(char s, va_list ap, long long *f);
char		*ft_cast_uns(char s, va_list ap, long long *f);
char		*ft_cast_str(char s, va_list ap);
int			ft_cast_wch(char s, va_list ap, long long *f, int *c);

char		*ft_con_int(long long i, long long *f);
char		*ft_con_uns(char s, unsigned long long i, long long *f);
int			ft_con_ptr(va_list ap, long long f, int *c);

char		*ft_itoabase_uns(unsigned long long n, int b, long long *f, char c);
int			ft_color(char *s, int i, int *c);

#endif
