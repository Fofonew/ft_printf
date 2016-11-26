/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:31:13 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/26 22:56:05 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			main(void)
{
	ft_printf("Real Returned %d\n", printf("%05d\n", 42));
	ft_printf("Test Returned %d\n", ft_printf("%05d\n", 42));
	return (0);
}
