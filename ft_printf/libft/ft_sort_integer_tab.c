/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:14:50 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/19 17:41:42 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_integer_tab(int *tab, int size)
{
	int a;
	int temp;

	a = 0;
	while (a < size - 1)
	{
		if (tab[a] > tab[a + 1])
		{
			temp = tab[a + 1];
			tab[a + 1] = tab[a];
			tab[a] = temp;
			a = 0;
		}
		else
			a++;
	}
}
