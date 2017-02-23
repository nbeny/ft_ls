/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:04:51 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/17 07:27:56 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*strjoin;
	unsigned int	i;
	unsigned int	j;

	if ((!s1 || !s2))
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	strjoin = (char *)malloc(sizeof(char) * (i + j + 1));
	if (strjoin == NULL)
		return (NULL);
	j = i;
	i = 0;
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		strjoin[j++] = s2[i++];
	strjoin[j] = '\0';
	return (strjoin);
}
