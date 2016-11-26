/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:31:13 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/26 20:18:13 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			main(void)
{
	printf("Real Returned %d\n", printf("%10%\n", 42));
	printf("Test Returned %d\n", ft_printf("%10%\n", 42));
	return (0);
}
