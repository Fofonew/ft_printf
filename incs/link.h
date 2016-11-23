/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 13:11:20 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/23 13:18:37 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINK_H
# define LINK_H

# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>

# define FG 2^

int				ft_printf(const char *s, ...);
int				ft_flags(char *s, long f);
int				ft_field(char *s);
int				ft_format(char *s, long f);

#endif
