/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 13:11:20 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/23 17:14:49 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINK_H
# define LINK_H

# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>

# define MIN 11
# define PRE 27

int				ft_printf(const char *s, ...);
int				ft_prim_flags(char *s, unsigned long *f);
int				ft_sec_flags(char *s, unsigned long *f);
int				ft_field(char *s, unsigned long *f, va_list ap);
int				ft_format(char *s, unsigned long *f, va_list ap, int *c);

size_t			ft_strlen(char *s);

#endif
