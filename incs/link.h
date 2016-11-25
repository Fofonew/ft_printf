/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 13:11:20 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/25 18:54:04 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINK_H
# define LINK_H

# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <wchar.h>

# include "libft.h"

# define MIN 11
# define PRE 27

int				ft_printf(const char *s, ...);
int				ft_flags(char *s, unsigned long *f);
int				ft_conv(char *s, unsigned long *f);
int				ft_field(char *s, unsigned long *f, va_list ap);
int				ft_format(char *s, unsigned long f, va_list ap, int *c);

int				ft_s(va_list ap, unsigned long f, int *c);
int				ft_p(va_list ap, unsigned long f, int *c);
int				ft_di(va_list ap, unsigned long f, int *c);
int				ft_dd(va_list ap, unsigned long f, int *c);
int				ft_o(va_list ap, unsigned long f, int *c);
int				ft_oo(va_list ap, unsigned long f, int *c);
int				ft_u(va_list ap, unsigned long f, int *c);
int				ft_uu(va_list ap, unsigned long f, int *c);
int				ft_x(va_list ap, unsigned long f, int *c, int t);
int				ft_c(va_list ap, unsigned long f, int *c);

int				ft_e(va_list ap, unsigned long f, int *c, int t);
int				ft_f(va_list ap, unsigned long f, int *c, int t);
int				ft_g(va_list ap, unsigned long f, int *c, int t);
int				ft_a(va_list ap, unsigned long f, int *c, int t);
int				ft_n(va_list ap, unsigned long f, int *c);

int				ft_b(va_list ap, unsigned long f, int *c);
int				ft_r(va_list ap, unsigned long f, int *c);
int				ft_k(va_list ap, unsigned long f, int *c);

int				ft_fd(va_list ap, unsigned long f, int *c);

#endif
