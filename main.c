/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:31:13 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/29 15:37:12 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <locale.h>

int			main(void)
{
	setlocale(LC_ALL, "");
	printf("Real Returned %d\n", printf("%C", L'ÁM-^L´'));
	printf("Test Returned %d\n", ft_printf("%C", L'ÁM-^L´'));
	return (0);
}
