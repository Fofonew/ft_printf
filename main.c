/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:31:13 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/30 13:17:50 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <locale.h>

int			main(void)
{
	setlocale(LC_ALL, "");
	printf("Real %d\n", printf("%15.4S", L"我是一只猫。"));
	printf("Test %d\n", ft_printf("%15.4S", L"我是一只猫。"));
	return (0);
}
