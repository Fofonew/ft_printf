/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:31:13 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/28 16:47:23 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			main(void)
{
	//printf("Real Returned %d\n", printf("%sHi%s", "\x1b[31m", "\x1b[0m"));
	printf("Test Returned %d\n", ft_printf("{red}red\n"));
	printf("Test Returned %d\n", ft_printf("{green}green\n"));
	printf("Test Returned %d\n", ft_printf("{yellow}yellow\n"));
	printf("Test Returned %d\n", ft_printf("{blue}blue\n"));
	printf("Test Returned %d\n", ft_printf("{magenta}magenta\n"));
	printf("Test Returned %d\n", ft_printf("{cyan}cyan\n"));
	printf("Test Returned %d\n", ft_printf("{eoc}white\n"));
	return (0);
}
