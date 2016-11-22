/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 13:11:20 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/20 17:09:48 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINK_H
# define LINK_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>

typedef struct	s_flags
{
	int			flags[11];
}				t_flags;

int				ft_printf(const char * restrict format, ...);
int				ft_flag(char *format, t_flags *flags);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
