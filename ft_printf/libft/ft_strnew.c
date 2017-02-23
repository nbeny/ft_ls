/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:44:06 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/16 10:26:08 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*strnew;

	strnew = (char *)malloc(sizeof(char) * (size + 1));
	if (strnew == NULL)
		return (NULL);
	ft_bzero(strnew, (size + 1));
	return (strnew);
}
