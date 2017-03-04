/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:57:33 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/01 16:45:24 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>

int		main()
{
	int		ret;

	ret = ft_printf("%*b\n", 50, 6546);
	ret = ft_printf("%*t\n", -5, 6546);
	ret = ft_printf("%*.*d\n", 0, 3, 1);
	ret = ft_printf("%o\n", 6546);
	ret = ft_printf("%n\n", 6546);
	ret = ft_printf("%u\n", 6546);
	ret = ft_printf("%x\n", 6546);
	ret = ft_printf("%v\n", 6546);
	return (0);
}
